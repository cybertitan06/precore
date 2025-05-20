#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) { //ok, so we've seen this int argc, char **argv business before, but what does it mean!?

	//argc and argv are just variable names. we could name them whatever we want, but it's extremely common to name them this
	//think of argc as the "ARGument Count", and argv as the "ARGument Vector"
	
	//notice that argc is an integer. This is because it holds the number of arguments passed into the function. One tricky piece of this, is that the value is ALWAYS at least 1. This is because the
	//first argument in the main function, is the name of the program. This is just part of how C works. Dont worry too much about it.
	
	//argv is a char **. This means it is a pointer to a pointer to a char. Don't freak out, we'll cover more about pointers later. It's easier to not think of it as a char double pointer,
	//rather, think of a char * as being a string, and char ** being an array of strings. We'll talk more about arrays later too.
	
	//together, these two arguments are super useful. we can use argc as an index in argv like so
	
	for (int i = 0; i < argc; i++) {
		printf("arg %d: %s\n",i, argv[i]);
	}
	printf("done\n");

	//Try running this program and passing in various arguments!
	return 0;
}
