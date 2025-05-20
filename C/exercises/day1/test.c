#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


//Try adding more assertions to this file, or write an additional function and test it.
//The only goal here is that you feel comfortable with the idea of code tests.

//Also, assertions can be effectively turned off if the code is compiled with -DNDEBUG.

int compare_func(int num, char* string);

//This example problem takes 2 arguments: a string, and a number
//and compares the number against the length of the string
int main(int argc, char **argv) {

   /* 
	* The C standard library includes a macro called assert()
	* The assert macro takes a boolean expression as an argument
	* If the expression evaluates to True, nothing happens.
	* If false, the program displays output to stderr, and calls abort()
	* assertions can be useful for catching edge cases and 
	* maintaining confidence that your code will function as expected.
    */

	assert(argc == 3); //this is not a great use for an assertion. An if statement would be better here.

	int num = atoi(argv[1]);
	char *string = argv[2];	

	//asserts are very useful for testing the various outputs of your code.
	//here, I make assertions about three cases I expect to always be true.
	assert(compare_func(1,"hello") == -1);
	assert(compare_func(5,"hello") == 0);
	assert(compare_func(10,"hello") == 1);

	compare_func(num,string);
	return 0;	
}


int compare_func(int num, char* string) {

	int string_len = strnlen(string,100);
	int compare;
	if (num > string_len){
		compare = 1;
	}
	else if (num < string_len) {
		compare = -1;
	}
	else {
		compare = 0;
	}
	return compare;
}
	
	
