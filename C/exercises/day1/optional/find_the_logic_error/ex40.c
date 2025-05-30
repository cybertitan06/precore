/**
 * Find and fix the logic error without dramatically changing the program.
 * @file ex40.c
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char firstWord[100] = "BuffalobuffaloBuffalobuffalobuffalobuffaloBuffalobuffalo";
    char secondWord[100] = "Yep, that's a real sentence according to Wiki.";
    char printMessage[100] = "Hello world!";

    printf("Length of first word is: %d \n", strlen(firstWord));
    printf("Length of second word is: %d \n", strlen(secondWord));
    
    if(strnlen(firstWord, 100) > strnlen(secondWord, 100)){
        printf("Result: %s.\n", printMessage);
    } else{
        printf("No dice!\n");
    }
    return 0;
}