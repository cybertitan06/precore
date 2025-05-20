#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char *string1 = "hello world\n";
	char string2[13] = {0};

	//use strncpy to copy string 1 into string 2

	printf("%s",string2);
	return 0;
}
