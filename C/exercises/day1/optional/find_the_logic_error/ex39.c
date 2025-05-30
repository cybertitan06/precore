/**
 * Find and fix the logic error without dramatically changing the program.
 * @file ex39.c
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char destination[100] = "Know";
    char source[100] = "No";

    char printMessage[100] = "Hello world!";

    
    if(strncmp(destination, source, 100) < 0){
        printf("Result: %s.\n", printMessage);
    } else{
        printf("No dice!\n");
    }
    return 0;
}