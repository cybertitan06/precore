#include <stdio.h>

int secondFunction(char *string)
{
    printf("%s\n", string);
    return 0;
}

int thirdFunction(char **string)
{
    //TODO: allocate a string and fill it in with some data
    return 0;
}

int fourthFunction(char *string)
{
    //TODO: fill out the buffer
    return 0;
}

int main(int argc, char *argv[])
{
    printf("Time for pointers.\n");
    //TODO: call seconfFunction with the argument pass_me
    char *pass_me = "Passed one successfully!\n";
    //call secondFunction

    // TODO: call thirdFunction with the argument pass_me2 and fill it out
    char *pass_me2 = NULL;
    //call thirdFunction
    printf("%s\n", pass_me2);

    //TODO: call fourthFunction with the argument pass_me3 and fill it out
    char pass_me3[25];
    //call fourthFunction
    printf("%s\n", pass_me3);


    return 0;
}

