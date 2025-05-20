#include <stdio.h>
#include <stdlib.h>

void changeMe()
{
    printf("Change this to the appropriate function\n");
}
/*
 * TODO:
 * @brief This will read a file into the provided buffer
 *
 * @param inputBuffer This is the buffer that will get the file contents
 * @param file This is a pointer to the file handle
 * @param fileSize This is the size of the file
 *
 * @return Return number of bytes read and -1 if failure
 *
 */
int readFile(char *inputBuffer, FILE* file, size_t fileSize)
{
    return -1;
}

/*
 * TODO:
 * @brief This opens a specified file
 *
 * @param fileName The name of the file you want to open
 *
 * @return Return file handle of a pointer
 *
 */
FILE *openFile(char *fileName)
{
    return 0;
}

/*
 * TODO:
 * @brief This gets the file size of a file
 *
 * @param file This is a file pointer to a file
 *
 * @return Return size of file
 *
 */
size_t getFileSize(FILE *file)
{
    return 0;
}

/*
 * TODO:
 * @brief Increases a buffer size to fit the specified file size
 *
 * @param buffer This is a pointer to the buffer's ptr which can be reallocated a new size
 * @param currentSize This is the current size of the buffer
 * @param sizeOfFile This is the size of the file you want to stuff inside the buffer
 *
 * @return Return 0 if successful. Return -1 if there was an error
 * hint: use realloc
 */
int increaseBufferSize(char **buffer, size_t currentSize, size_t sizeOfFile)
{
        
    return -1;
}


int main(int argc, char *argv[])
{

    //DO NOT CHANGE THIS MALLOC SIZE
    char *inputBuffer = malloc(1);

    // Get a handle to a file
	char *filepath = "file.txt"
    FILE *file = changeMe();

    // Get file size of file
    size_t fileSize = changeMe();

    // Resize buffer
    if (increaseBufferSize(&inputBuffer, 1, fileSize) < 0)
    {
        printf("Could not increase buffer size!!\n");
        return -1;
    }

    // Read file
    int numRead = readFile(inputBuffer, file, fileSize);
    if (numRead != fileSize)
    {
        printf("Could not all of file!!\n");
        return -1;
    }

    //TODO free the allocated memory!!
    changeMe();

    return 0;
}
