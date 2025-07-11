/**
 * Create a C program that only accepts a value from the user and sums up all values below that.
 * E.g.
 * "5+4 = 9+3= 12+2= 14+1= 15"
 * The program output should print the final result.
 * ./ex20-goal 5
 * "15"
 * This time, user input is NOT done for you!
 * @file ex33.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc < 2){
        /*
        *   Usage: ./ex21-goal <#>
        *       ./ex21-goal 5
        */
        printf("Usage: %s <#>\n\t%s 5\n", argv[0], argv[0]);
        return -1;
    }

    int user_input = atoi(argv[1]);
    int sum;

    for(int i = user_input; i > 0; i--){
        sum += i;
    }
    
    printf("Final sum for %d is %d.\n", user_input, sum);
    return 0;
}
