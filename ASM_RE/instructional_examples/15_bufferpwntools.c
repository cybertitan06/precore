/*
*
* This is an example meant to be used with pwntools
* Compile with: gcc -m32 -O0 -gdwarf-2 -fno-stack-protector -no-pie -fno-pie -z execstack -z norelro -o 15_bufferpwntools 15_bufferpwntools.c
* 
*/


#include <stdio.h>

int vuln() {

    char buffer[20] = { 0 };
    printf("Cup: %p\n", buffer);
    printf("Fill the cup til it overflows:\n");
    scanf("%s", buffer);

    return 0;
}

int main() 
{
    vuln();
    return 0;
}

