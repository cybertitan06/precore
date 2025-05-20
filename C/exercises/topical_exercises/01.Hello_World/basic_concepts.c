/*
 *This is a multiline comment. it starts with a forward slash and a star, and ends with a star and a forward slash. 
 *Normally, we would put a description of our code up here at the top, though the exact placement is up to you. Some people like to put the #include lines first 
 *
 *speaking of #include, the two statments below tell our program "I intend to use code that is declared in the stdio and stdlib header files." 
 *
 *stdio is the Standard Input/Output file. You'll probably include this in every C program you ever write. This file includes the code for taking input from the user, and returning output to the screen, but it
 *also does a lot more than that.
 * 
 *stdlib is the Standard Library, which, as you can imagine, holds a ton of very commonly used functions. it includes defining the NULL macro, the memory allocation functions (malloc, calloc, realloc), as
 *well as atoi and more.
 */

#include <stdio.h>
#include <stdlib.h>

//this is a single line comment. it starts with a double forward slash.

//here we define our main function. Every C program MUST have a main function. 
int main(int argc, char **argv) { //here we say "I am creating a function called main, that returns an integer, and takes two arguments: an integer, and char double pointer" 
	printf("hello World!\n"); //printf is the most common function for printing output. it includes support for special formatting characters like the backslash N which acts as a line break.
	return 0; //we are done with our function so we must use return to tell the program that we are done. We return 0 because our main function must return an int, and 0 is the return value that most
		  //commonly means "normal execution. no errors to report"
}

//if we want to run our program, we have to compile it. The easiest way to do this is with the gcc command line utility.

//try compiling this program as follows: gcc -o helloworld helloworld.c

//the above line says "use gcc to compile helloworld.c, and when you're done, store the resulting executable under the name helloworld." the -o flag lets us name our executable whatever we want.
//if you leave it out, your executable will be given a default name.
