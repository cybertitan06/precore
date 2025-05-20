/**
 * files.c contains all of the functionality for the download and upload commands.
 * @file files.c
 */

#include <files.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <string.h>
#include <arpa/inet.h>

static uint32_t deserialize_upload_file_path(char *upload_args, char **file_path_out);
static uint32_t deserialize_upload_file_contents(char *upload_args, uint32_t file_path_len, char **contents_out);

/**
 * @brief opens file specified by parameter passed, puts the contents in contents_out and returns the size.
 * @param filename filename to open
 * @param contents_out a NULL pointer that will contain the contents of the file or NULL on error
 * @return an integer representing the number of bytes read
 */ 
uint32_t read_file(char *filename, char **contents_out)
{
    uint32_t read_counter;
    // open the file handle in read bytes mode
    // allocate our initial read buffer
    // get file contents
    return read_counter;
}

/**
 * @brief Write the contents of a stream to a specified file.
 * @param filename the name of the file to write to
 * @param contents a pointer to the contents that will be written
 * @param contents_size the size of the contents
 * @return returns the number of bytes written to the file
 */
uint32_t write_file(char *filename, char *contents, uint32_t contents_size)
{
    uint32_t write_counter = 0;

    // open the file handle in write bytes mode
    // write contents

    return write_counter;
}

/**
 * @brief Download the file specified in the Command args.
 * @param cmd the download command with arguments
 * @return a Response where the message is the file byte stream
 */
Response *download_file_command(Command *cmd)
{

    Response *rsp = NULL;
    
    // open the file handle in read bytes mode
    // Send contents
    return rsp;

}

/**
 * @brief deserialize the file path and file path length from upload arguments.
 * @param upload_args the full upload arguments passed in the command structure
 * @param file_path_out a NULL pointer that will contain the file path on success or NULL on error
 * @return the length of the file path
 */
static uint32_t deserialize_upload_file_path(char *upload_args, char **file_path_out)
{
    uint32_t file_path_len;
    // refer to the README.md to inform how to deserialize just the upload path
    return file_path_len;
}

/**
 * @brief deserialize the file contents and contents length from upload arguments.
 * @param upload_args the full upload arguments passed in the command structure
 * @param file_path_len length of the already deserialize file path
 * @param contents_out a NULL pointer that will contain the file contents on success or NULL on error
 * @return the length of the file path
 */
static uint32_t deserialize_upload_file_contents(char *upload_args, uint32_t file_path_len, char **contents_out)
{
    uint32_t content_len;
    // refer to the README.md to inform how to deserialize just the file contents
    return content_len;
}

/**
 * @brief Upload the file specified in the command arguments.
 * @param cmd the command structure
 * @return a response indicating upload success or failure
 */
Response *upload_file_command(Command *cmd)
{
    Response *rsp = NULL;
    
    // Deserialize path and contents
    // Write file
    
    return rsp;
}
