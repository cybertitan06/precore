/**
 * A macro is utilized to enable and disable segments of code.
 * Your goal is to have "Hello World!" printed to the console screen.
 * @file ex12.c
 *
 * You do NOT need to modify this code AT ALL. Instead, try changing how you compile this code...
 * if you're stuck, check out the different flags that gcc supports
 */

#include <stdio.h>

#ifdef PRODUCTION
#define MODE 1
#else
#define MODE 0
#endif

int main(int argc, char **argv) {
    #ifdef _DEBUG
    #if MODE == 0
    printf("Hello World!\n");
    
    #endif
    #else
    printf("This application is in production\n");
    #endif

    return 0;
}
