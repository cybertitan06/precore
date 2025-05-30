/**
 * Time to make a game!
 * You will create a C program number guessing game.
 * The behavior should be similar to the sequence below.
 *      1. Generate a random number between X and Y
 *      2. Ask the user to guess the number
 *      3. Reply with something similar to the following answers depending on the guess and comparison.
 *          1. Too High!
 *          2. Too Low!
 *          3. Got it!
 * It's up to you if you want to look ahead and create loops or if you want to just rerun the application every time. 
 * As a push goal if you use a loop, try to implement a # of guesses system which causes the user to lose after a 
 * certain number.
 * @file ex35.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess_match(int user, int computer){
    if (user == computer)
        printf("Got it!\n");    
    else if (user < computer)
        printf("Too low!\n");
    else
        printf("Too high!\n");
}

int main(int argc, char **argv) {
    //Initialize counting variables and randomize number to be guessed
    srand(time(0));
    int computer_number = rand() % 11;
    int user_guess;
    int initial_guess_counter = 5;
    int guess_counter = initial_guess_counter;

    //Take user input, compare it to the computer number, and either decrement the counter or exit the program
    for(int i = 0; i < initial_guess_counter; i++){
        printf("Enter a number between 0 and 10: ");
        scanf("%d", &user_guess); 
        guess_match(user_guess, computer_number);
        if (user_guess == computer_number)
            break;
        guess_counter--;
        printf("You have %d guesses remaining.\n", guess_counter);
    }
    printf("Computer number was %d.", computer_number);
    return 0;
}
