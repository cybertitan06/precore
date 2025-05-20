#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char string1[32] = "hello ";
	char string2[32] = "world!"; //note that we allocate extra space for these strings so that we don't cause a segfault with strcat

	char *string3 = //use the strncat function to set string 3 equal to hello world
	printf("%s\n",string3); //note that strcat also modifies string1
	return 0;
}
