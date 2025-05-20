#include <stdio.h>
#include <stdlib.h>

//finish the program that it prints "Hello, world!" if x is greater than y using a ternary statement
//
//recall that ternary syntax is <any statement that evaluates to true or false> ? <expression that is evaluated if statement is true> : <expression that is evaluated if statement is false>
//an example has been provided for you in the function below.

void main() {
	int x = 10;
	int y = 5;

	char *example = (x == y) ? "x is equal to y\n" : "x is not equal to y\n";
	printf(example);
	
	//the above ternary is equivalent to this if statement:
	char *anotherExample = NULL;
	if (x==y) {
		anotherExample = "x is equal to y\n";
	}
	else {
		anotherExample = "x is not equal to y\n";
	}
	printf(anotherExample);

	char *hello_msg = "Hello, world!\n";
	char *goodbye_msg = "Goodbye, cruel world! D: \n";

	char *msg = //insert ternary statement here
	printf(msg);
	return;
}
