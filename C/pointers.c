#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pointer_function(char **pIn, int *pA){

    if(!pIn || !pA)
        return;

    *pA = 3;
    *pIn = calloc(1,7);
    strcpy(*pIn,"hello!");
}

int main(){

    char *ptr = NULL;
    char str[7] = "hello!";
    int a = 1;


    //strcpy(pstr, "hello!");
    pointer_function(&ptr, &a);
    printf("%s\n", ptr);
    printf("%p is the address of %d.", &a, a);

    free(ptr);
    ptr = NULL;

    return 0;
}