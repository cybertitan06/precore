#include <stdio.h>
#include <stdlib.h>

/*
 * Test shellcode from a file - this program will read the file into a buffer and then execute the buffer.
 *
 * Compile with:
 * gcc -z execstack -fno-stack-protector -o test_shellcode test_shellcode.c
*/

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    char shellcode[512];

    FILE *f = fopen(argv[1], "r");
    if (NULL == f) {
        printf("Failed to open file: %s\n", argv[1]);
        exit(1);
    }
    fread(shellcode, sizeof(char), 512, f);
    fclose(f);
    ((void (*)()) shellcode) ();
    return 0;
}