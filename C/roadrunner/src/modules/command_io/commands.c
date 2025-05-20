/**
 * commands.c contains all of the functionality for serializeing and deserializing commands and responses.
 * @file commands.c
 */

#include <commands.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdbool.h>
#include <utils.h>

/**
 * @brief Deserialize a message stream of bytes into a Command structure.
 * @param msg_size (in) the total message stream size
 * @param msg_stream (in) a pointer to the message stream
 * @return a pointer to a Command structure or NULL on error
 */
Command *deserialize_command(uint32_t  msg_size, char *msg_stream)
{
    // Validate command received
    // Get bytes
    // convert from network to host byte order
    // store command in struct
    return NULL;
}

/**
 * @brief Allocate the memory and store data in a new Command structure.
 * @param cmd (in) pointer to the cmd bytes
 * @param cmd_len (in) the size of the cmd
 * @param args (in) pointer to the args bytes
 * @param args_len (in) the size of the args
 * @return a pointer to an empty Command structure or NULL on error
 */
Command *alloc_command(char *cmd, uint32_t cmd_len, char *args, uint32_t args_len)
{
    Command *new_cmd = calloc(1, sizeof(Command));
    // if we get a null then there are memory issues and we need to bail
    if(new_cmd == NULL)
    {
        return new_cmd;
    }
    new_cmd->cmd = calloc(cmd_len, sizeof(char));
    memcpy(new_cmd->cmd, cmd, cmd_len);
    new_cmd->cmd_len = cmd_len;
    new_cmd->args = calloc(args_len, sizeof(char));
    memcpy(new_cmd->args, args, args_len);
    new_cmd->args_len = args_len;
    return new_cmd;
}

/**
 * @brief Free a Command structure and its components.
 * @param cmd a pointer to a Command structure
 */
void free_command(Command *cmd)
{
    if(cmd != NULL)
    {
        checkfree(cmd->cmd)         
        checkfree(cmd->args)
        free(cmd);
    }
}

/**
 * @brief Serialize a Response structure into a byte stream.
 * @param rsp (in) a pointer to a Response structure
 * @param stream_out (out) a NULL char pointer where the stream will be passed back out
 * @return the total size of the stream
 */
uint32_t serialize_response(Response *rsp, char **stream_out)
{
    // initialize variables
    uint32_t total_size = 0;

    // calculate the total size of the message
    // Convert to network byte order
    // copy each part of the message into the stream
    return total_size;
}

/**
 * @brief Allocate memory for a Response structure.
 * @param ret_code (in) the integer return code
 * @param msg (in) the message stream
 * @param msg_len (in) the size of the message stream
 * @return a pointer to a Response structure or NULL on error
 */
Response *alloc_response(int32_t ret_code, char* msg, uint32_t msg_len)
{
    Response *rsp;
    rsp = calloc(1, sizeof(Response));

    // if we get a null then there are memory issues and we need to bail
    if (rsp == NULL)
    {
        return rsp;
    }

    rsp->ret_code = ret_code;
    rsp->msg_len = msg_len;

    // need to include the null terminator
    rsp->msg = calloc(msg_len, sizeof(char));
    memcpy(rsp->msg, msg, msg_len);

    return rsp;
}

/**
 * @brief free a Response structure and its components.
 * @param rsp pointer to a Response structure
 */
void free_response(Response *rsp)
{
    
    // check to see if the Response structure is NULL
    if(rsp != NULL)
    {
        // free the message stream
        checkfree(rsp->msg)
        // free the whole structure  
        free(rsp);
    }
}

