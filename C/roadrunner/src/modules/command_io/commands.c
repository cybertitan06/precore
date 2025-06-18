/**
 * commands.c contains all of the functionality for serializeing and deserializing commands and responses.
 * @file commands.c
 */

#include <commands.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdbool.h>
#include <utils.h>
#include <stdio.h>

void dump_mem(void *location, size_t bytes){    //Brandon's function to print out memory at a given location
    size_t i = 0;
    for (i = 0; i<bytes; i++){
        if (0 == (i%16)){
            printf("\n");
        }
        uint8_t curr = ((uint8_t *)location)[i];
        printf(" %2X ", curr);
    }
}

/**
 * @brief Deserialize a message stream of bytes into a Command structure.
 * @param msg_size (in) the total message stream size
 * @param msg_stream (in) a pointer to the message stream
 * @return a pointer to a Command structure or NULL on error
 */
Command *deserialize_command(uint32_t  msg_size, char *msg_stream)
{
    if(msg_size == 0 || !msg_stream){   //Check if a msg_stream was passed in or if msg_size is not zero
        return NULL;
    }

    Command *new_cmd = NULL;
    uint32_t cmd_length = 0;
    char *cmd = NULL;
    uint32_t args_length = 0;
    char *args = NULL;

    uint32_t offset = sizeof(uint32_t);
    uint32_t stream_size = 0;

    //Copy the expected cmd_length value from the msg_stream into its variable. Increment the offset by the cmd_length datatype (uint32_t)
    memcpy(&cmd_length, msg_stream+offset, sizeof(uint32_t));
    offset += sizeof(uint32_t);

    //Translate from network to host order & reload into the cmd_length variable
    cmd_length = ntohl(cmd_length);

    if(cmd_length > msg_size){      //Will index beyond msg_stream buffer
        printf("Cmd length is too big\n");
        return NULL;
    }

    //Allocate memory for the cmd property based on the cmd_length value. Assign the cmd pointer to this memory block
    cmd = calloc(cmd_length, sizeof(char));

    //Copy the expected cmd value from the msg_stream into its variable. Increment the offset by the cmd_length value
    memcpy(cmd, msg_stream + offset, cmd_length);
    offset += cmd_length;

    if(cmd == NULL || cmd_length != strlen(cmd)){
        printf("Cmd is NULL or cmd_len does not match cmd length\n");
        goto CLEANUP;
    }

    //Copy the expected args_length value from the msg_stream into its variable. Increment the offset by the args_length datatype (uint32_t)
    memcpy(&args_length, msg_stream + offset, sizeof(uint32_t));
    offset += sizeof(uint32_t);

    //Translate from network to host order & reload into the args_length variable
    args_length = ntohl(args_length);

    if(args_length > msg_size){         //Will index beyond the msg_stream buffer
        printf("Args length is too big\n"); 
        goto CLEANUP;
    }

    //Allocate memory for the args property based on the args_length value. Assign the args pointer to this memory block
    args = calloc(args_length, sizeof(char));

    //Copy the expected args_length value from the msg_stream into its variable. Increment the offset by the args_length value
    memcpy(args, msg_stream + offset, args_length);

    stream_size = sizeof(uint32_t) * 3 + cmd_length + args_length;

    //Verify message size is good
    if(msg_size != stream_size){
        printf("Msg size does not match\n");
        goto CLEANUP;
    }

    //Create new command
    new_cmd = alloc_command(cmd, cmd_length, args, args_length);

    //Free up memory of args I've calloc'd (cmd & args)
    free(cmd);
    cmd = NULL;
    free(args);
    args = NULL;

CLEANUP:
    if(cmd != NULL || args != NULL){
        free(cmd);
        cmd = NULL;
        free(args);
        args = NULL;
        return NULL;
    }

    return new_cmd;
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
    //Initialize local variables
    uint32_t total_size = 0;
    uint32_t ret_code = 0;
    char *msg = NULL;
    uint32_t msg_len = 0;

    ret_code = rsp->ret_code;
    msg_len = rsp->msg_len;
    msg = rsp->msg;
    total_size = 3 * sizeof(uint32_t) + msg_len;
    *stream_out = calloc(total_size, sizeof(char));

    //Ensure *rsp is not NULL
    if (!rsp || !(rsp->msg) || (rsp->msg_len) <= 0 || (rsp->ret_code) < 0){    
        
        printf("Some response property is null or missing\n");
        return -1;
    }

    // Convert to network byte order
    uint32_t ser_total_size = htonl(total_size);
    uint32_t ser_ret_code = htonl(ret_code);
    uint32_t ser_msg_len = htonl(msg_len);

    // copy each part of the message into the stream
    uint32_t offset = 0;
    memcpy(*stream_out + offset, &ser_total_size, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    memcpy(*stream_out + offset, &ser_ret_code, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    memcpy(*stream_out + offset, &ser_msg_len, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    memcpy(*stream_out + offset, msg, msg_len);

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
        checkfree(rsp->msg);
        // free the whole structure  
        free(rsp);
    }
}

