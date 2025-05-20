/**
* Qsort is a standard library function that can sort anything you want! Write comparison functions 
* that can sort the provided arrays.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int int_compare(const void *a, const void *b);
int strlen_compare(const void *a, const void *b);

void main() {

	int int_array[] = { 2, 9, 17, 32, 97, 28, 7, 39, 22, 75, 60, 1, 50, 8};
	char* word_array[] = {"boy","arrays", "doorknob", "fantastical", "at", "sting", "a"};

	//the definition of qsort is as follows
	//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
	//base = the pointer to the first element in the array you want to sort
	//nitems = the number of elements in the array
	//size = the size of the elements in the array in bytes (e.g. sizeof(int))
	//compar = the function qsort will use to compare values in the array

	printf("before sorting int_array:\n");
	for (int i = 0; i<14; i++) {
		printf("%d ",int_array[i]);
	}
	printf("\n\n");

	qsort(int_array,14,sizeof(int),int_compare);

	printf("after sorting int array:\n");
	for (int i = 0; i<14; i++) {
		printf("%d ",int_array[i]);
	}
	printf("\n\n");


	printf("before sorting word_array:\n");
	for (int i = 0; i<7; i++) {
		printf("%s ",word_array[i]);
	}
	printf("\n\n");

	//use qsort to sort word_array

	printf("after sorting word array:\n");
	for (int i = 0; i<7; i++) {
		printf("%s ",word_array[i]);
	}
	printf("\n\n");

	return;
}

int int_compare(const void *a, const void *b) {
	//this function should return positive if a is greater than b
	//negative if a is less than b
	//and zero if they are equal
	return 0;
}

//be mindful of what qsort is actually giving you here.
//a and b are pointers to objects in an array.
int strlen_compare(const void *a, const void *b){
	//this function should return positive if a is longer than b
	//negative if a is shorter than b
	//and zero if they are equal
	return 0;
}
