#include <stdio.h>

//This exercise does not require you to code anything. it is only meant to demonstrate how atoi works.

void main(int argc, char **argv) {
	if (argc == 1){
		printf("usage: ./atoi_exercise 3\n");
		return;
	}
	int num = atoi(argv[1]);
	printf("the number you provided is %d\n",num);
	return;
}
