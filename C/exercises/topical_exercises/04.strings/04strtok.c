#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	printf("Split the following sentence by spaces and print out each one with its index\n");
	char *split_me = "What an amazing sentence this is.\n";
	printf("%s\n", split_me);


	//INSERT YOUR CODE HERE

	printf("Split the following output by each \":\" character and print each field with an index, name, and value\n");
	char *split_me_pt2 = "Name:	ghex\nUmask:	0022\nState:	S (sleeping)\nTgid:	3604\nNgid:	0\nPid:	3604\nPPid:	2256";
	printf("%s\n", split_me_pt2);

	//INSERT YOUR CODE HERE
	
	return 0;
}
