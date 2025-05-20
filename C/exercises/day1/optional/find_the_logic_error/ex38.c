/**
 * Find and fix the logic error without dramatically changing the program.
 * @file ex38.c
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char helloPart[100] = "Hello ";
    char worldPart[100] = "world!";

    char printMessage[100] = {'\0'};

    strncat(helloPart, printMessage, strlen(worldPart));
    strncat(worldPart, printMessage, strlen(helloPart));

    printf("Result: %s.\n", printMessage);
    return 0;
}
