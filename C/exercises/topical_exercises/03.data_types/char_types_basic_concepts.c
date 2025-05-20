#include <stdio.h>
#include <stdlib.h>

//This exercise does not require you to code anything. It is for demonstration purposes only.
int main(int argc, char **argv) {
	
	char single_character = 'a';
	char another_char = '4';
	char one_more_char = '%';

	/* As I'm sure you've picked up by now, the char datatype holds a single character.
	 * this doesn't necessarily mean it is a single byte though. the size of a char can vary just like the size of 
	 * an int can from computer to computer.
	 */

	char *string = "char * acts like a string!";

	/*
	 *the char * is simple a pointer to a char. The reason this is important, is because it lets us 
	 *declare variables like the one above. The pointer will actually point to the first letter in
	 *in the string ('c' in this case), and the rest of the sentence is actually treated like an
	 *array, where each element is the next symbol in the string
	 *
	 * The following two variables are equivalent:
	 */

	char *string1 = "hello"; //in this example we implicity declare an array using the pointer to char type
	char string2[] = {'h','e','l','l','o'}; //in this example we explicity declare an array, and initialize it with the values we want in our string

	return 0;
}
