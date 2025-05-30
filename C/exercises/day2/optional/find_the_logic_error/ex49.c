/**
 * Find and fix the logic error without dramatically changing the program.
 * @file ex49.c
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char gibberish[100] = "BuffalobuffaloBuffalobuffaloHello World!buffalobuffaloBuffalobuffalo";
    char printMessage[100] = {'\0'};

    char *pIter = strstr(gibberish, "Hello World!");

    int i = 0;
    do{
        printMessage[i] = pIter[i];
        i++;
    } while (pIter[i] != 'b');
    printf("Result: %s.\n", printMessage);

    return 0;
}
