/**
 * 
 * Create a C program that only prints out the first X values
 * of an array..
 * The program output should print to console each value up
 * to the request number.
 * ./ex20-goal 5
 * "1 2 3 4 5" 
 * This time, user input is NOT done for you!
 * @file ex31.c
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc < 2){
        /*
        *   Usage: ./ex31 <#>
        *       ./ex31 5
        */
        printf("Usage: %s <#>\n\t%s 5\n", argv[0], argv[0]);
        return -1;
    }
    // 'numberArray' contains the values to print out.
    int numberArray[100] = {0};
    for(int i=1; i<101; i++){ numberArray[i-1] = i; }

    // Add code to print out the numbers below this point!
    int array_counter = atoi(argv[1]);

    //Error check to make sure number does not exceed array
    if (array_counter > 100){
        printf("Number must be below 100.\n");
        return -1;
    }    
    
    for(int i = 0; i < array_counter; i++)
        printf("%d ", numberArray[i]);
    
    return 0;
}
