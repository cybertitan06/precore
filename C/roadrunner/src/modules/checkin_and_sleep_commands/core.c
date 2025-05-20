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
    // Return "roadrunner checkin" in response
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
    char *base_msg = "road runner slept for %s second(s)";    
    return rsp;
}
