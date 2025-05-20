#include <stdio.h>
#include <stdlib.h>

char *stringchanger(char *inputstring);
int increment(int num);

void main() {

	char hello[] = "hello";
	stringchanger(hello);
	printf("%s\n",hello); 
	//so far so good.
	int x = 5;
	increment(x);
	printf("the value of x is: %d\n",x);	
	//hmm, why did that work for the string but not the int?
	//Lets try this again in the next section with pointers...
	return;
}

char *stringchanger(char *inputstring) {
	inputstring[0] = 'j'; //now it will say jello instead of hello lol.
	return inputstring;
}

int increment(int num){
	return num+1;
}
