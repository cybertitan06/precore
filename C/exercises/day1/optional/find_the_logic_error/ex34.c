/**
 * Find and fix the logic error.
 * @file ex34.c
 */

#include <stdio.h>

int main(int argc, char **argv) {
    char *successMessage = "Hello world!";
    char *failureMessage = "Buuuuurt! Incorrect!";
    
    int a = 0;
    char *printMessage = (a==0)? successMessage : failureMessage;
    printf("%s\n", printMessage);
    return 0;
}
