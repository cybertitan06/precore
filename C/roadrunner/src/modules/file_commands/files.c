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
#include <fcntl.h>

#define READ_SIZE 100
#define WRITE_SIZE 100

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
    ssize_t read_counter = 0;
    uint32_t total_read = 0;
    char *temp = NULL;
    int fd = 0;

    if (filename == NULL)
        goto END;

    // open the file handle in read bytes mode
    fd = open(filename, O_RDONLY);
    if(fd == -1)
        goto END;

    // allocate our initial read buffer
    *contents_out = malloc(READ_SIZE);

    // get file contents 
    while (read_counter != -1){
        read_counter = read(fd, *contents_out + total_read, READ_SIZE);

        if (read_counter == 0)
            break;
        
        if (read_counter == -1)
            goto CLEANUP;
            
        total_read += read_counter;

        temp = realloc(*contents_out, total_read + READ_SIZE);
        if (temp == NULL)
            goto CLEANUP;
        
        *contents_out = temp;
    }

    goto END;

CLEANUP:
    //cleanup on failure
    if (*contents_out != NULL){
        free(*contents_out);
        *contents_out = NULL;
    }

END:
    close(fd);
    return total_read;
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
    ssize_t write_counter = 0;
    uint32_t total_write = 0;
    int fd = 0;
    char *temp = NULL;
    
    if (contents == NULL)
        goto END;
  // open the file handle in write bytes mode
    fd = open(filename, O_WRONLY | O_CREAT);
    if(fd == -1)
        goto END;
    
    contents = malloc(contents_size);
   
    // write contents
    while (write_counter != -1){
        
        if (contents_size == total_write)
            break;

        write_counter = write(fd, contents + total_write, contents_size);
        // ssize_t write(int )fd, const void buf[.count], size_t count);

        if (write_counter == 0){
            printf("Content size is %d", contents_size);
            break;
        }
        
        if (write_counter == -1)
            goto CLEANUP;

        
        total_write += write_counter;

        temp = realloc(contents, total_write + contents_size);
        if (temp == NULL)
            goto CLEANUP;
        
        contents = temp;
    }

    goto END;

CLEANUP:
    //cleanup on failure
    if (contents != NULL){
        free(contents);
        contents = NULL;
    }

END:
    close(fd);  
    return total_write;
}

/**
 * @brief Download the file specified in the Command args.
 * @param cmd the download command with arguments
 * @return a Response where the message is the file byte stream
 */
Response *download_file_command(Command *cmd)
{

    Response *rsp = NULL;
    int32_t ret_code = 0;
    char *contents_out = NULL;
    uint32_t bytes_read = 0;

    if (!cmd || !(cmd->cmd) || (cmd->cmd_len) <= 0 || !(cmd->args) || (cmd->args_len) <= 0){    
        ret_code = 1;
        contents_out = calloc(1, strlen("error downloading file")+1);
        strncpy(contents_out, "error downloading file", strlen("error downloading file")+1);

        goto done;
    }
    
    //RESEARCH
    bytes_read = read_file(cmd->args, &contents_out);

    if (bytes_read == 0){
        ret_code = 1;
        contents_out = calloc(1, strlen("error downloading file")+1);
        strncpy(contents_out, "error downloading file", strlen("error downloading file")+1);
        
        goto done;
    }

done:
    rsp = alloc_response(ret_code, contents_out, strlen(contents_out) + 1);
    if (contents_out){
        free(contents_out);
        contents_out = NULL;
    }    
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
