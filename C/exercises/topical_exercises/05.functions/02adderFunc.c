#include <stdio.h>
#include <stdlib.h>

void main() {
	int x = add(2,2);
	if (4 == x){
		printf("hello world!\n");
	}
	return;
}

//define the function called "add" here. It should take two args, both of which should be an int, and return the sum of those two ints
//also, notice that I have not provided the function prototype for you this time. since our code will all reside within a single file, 
//we could actually get away with skipping the function prototype, as long as we defined the add function before we defined main, but 
//thats not what I want you to do for this exercise. 
