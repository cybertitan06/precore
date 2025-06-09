/**
 * core.c contains all of the functionality for the core RoadRunner commands, checkin and sleep.
 * @file core.c
 */

#include <core.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Check in with the RoadRunner command post.
 * @return a Response structure
 */
Response *checkin_command()
{
    Response *rsp = NULL;
    char *msg = NULL;
    uint32_t msg_len = 0;
    msg = "roadrunner checkin";
    msg_len = strlen(msg);
    
    // Return "roadrunner checkin" in response
    rsp = alloc_response(0, msg, 19);

    return rsp;
}
 
/**
 * @brief Command to have RoadRunner sleep for a specified number of seconds.
 * @param cmd the command structure
 * @return a Response structure
 */
Response *sleep_command(Command *cmd)
{
    // Perform sleep and return base msg with how long the agent was commanded to sleep

    Response *rsp = NULL;
    int sleep_timer = 0;
    char *contents_out = NULL;
    char *args = NULL;
    uint32_t ret_code = 0;

    //Check for NULL
    if (!cmd || !(cmd->cmd) || (cmd->cmd_len) <= 0 || !(cmd->args) || (cmd->args_len) <= 0){
        ret_code = 1;
        contents_out = calloc(1, strlen("arguments provided are NULL")+1);
        strncpy(contents_out, "arguments provided are NULL", strlen("arguments provided are NULL")+1);
        goto CLEANUP;
    }

    //Check for bad arguments
    if(atoi(cmd->args) <= 0){
        ret_code = 1;
        contents_out = calloc(1, strlen("arguments are not of the correct type")+1);
        strncpy(contents_out, "arguments are not of the correct type", strlen("arguments are not of the correct type")+1);
        goto CLEANUP;
    }

    //Pass sleep command to local sleep variable
    sleep_timer = atoi(cmd->args);
    sleep(sleep_timer);

    //Add sleep variable to base msg
    char *base_msg = "road runner slept for %s second(s)";
   
    int size = strlen(base_msg) + 20;
    char* temp_msg = (char*) calloc(size, sizeof(char));
    snprintf(temp_msg, size, base_msg, cmd->args);

    rsp = alloc_response(0, temp_msg, strlen(temp_msg));
    goto END;
    
CLEANUP:
    rsp = alloc_response(ret_code, contents_out, strlen(contents_out));

    if (contents_out){
        free(contents_out);
        contents_out = NULL;
    }

END:
    return rsp;
}