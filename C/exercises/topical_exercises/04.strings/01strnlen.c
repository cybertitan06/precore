#include <stdio.h>
#include <stdlib.h>
#include <string.h> //This header file has tons of useful functions!

int main(int argc, char **argv) {
	char *string = "hello World!\n";
	int string_length = //use the strnlen function to set this variable equal to the length of the string above
	//note that we could also use strlen here, but strnlen is safer! it's best practice to use strnlen!
	
	printf("our string has a length of %d\n",string_length);
	return 0;
}
