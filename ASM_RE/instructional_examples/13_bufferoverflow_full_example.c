/*
 * A simple buffer overflow example.  In this example our program reads the contents of a file up to 0x1000 bytes into a
 * 16 byte buffer.  Let's see if we can exploit this vulnerability to execute some shellcode
 *
 * Make sure ASLR is disabled:
 * $ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'
 *
 * Compile with:
 * $ gcc -m64 -O0 -gdwarf-2 -fno-stack-protector -no-pie -z execstack -z norelro -o 13_bufferoverflow_full_example 13_bufferoverflow_full_example.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility function to help print out stack contents
char *get_contents_64(unsigned char *addr, char *fmt, int fmtsize) {
    char *result = calloc(17, 1);
    for (int i = 0; i < 8; i++) {
        unsigned char cur_char[3] = {0};
        if (strcmp(fmt, "%c") == 0 && (addr[i] < 32 || addr[i] > 127)) {
            cur_char[0] = '.';
        } else {
            snprintf(cur_char, 3, fmt, addr[i]);
        }
        strncpy(result+i*fmtsize, cur_char, 2);
    }

    return result;
}

// Utility function to print the contents of the stack to the terminal
void print_stack(char *buffer, char *context) {
    printf("-------------------------------------\n");
    printf("%p | %s | %s <-- buffer[0]\n", buffer, get_contents_64(buffer, "%02x", 2), get_contents_64(buffer, "%c", 1));
    printf("%p | %s | %s <-- buffer[8]\n", buffer+0x08, get_contents_64(buffer+0x08, "%02x", 2), get_contents_64(buffer+0x08, "%c", 1));
    printf("%p | %s | %s <-- RBP\n", buffer+0x10, get_contents_64(buffer+0x10, "%02x", 2), get_contents_64(buffer+0x10, "%c", 1));
    printf("%p | %s | %s <-- Return address\n", buffer+0x18, get_contents_64(buffer+0x18, "%02x", 2), get_contents_64(buffer+0x18, "%c", 1));
    printf("-------------------------------------\n");
    printf("%p | %s | %s <-- %s\n", buffer+0x20, get_contents_64(buffer+0x20, "%02x", 2), get_contents_64(buffer+0x20, "%c", 1), context);
    printf("%p | %s | %s\n", buffer+0x28, get_contents_64(buffer+0x28, "%02x", 2), get_contents_64(buffer+0x28, "%c", 1));
    printf("%p | %s | %s\n", buffer+0x30, get_contents_64(buffer+0x30, "%02x", 2), get_contents_64(buffer+0x30, "%c", 1));
    printf("...\n");
    printf("...\n");
    printf("-------------------------------------\n\n");
}

// A vulnerable function that will be the target of our exploit
int vuln(FILE *pFile) {
    char buffer[0x10] = {};

    printf("The stack before fread() call:\n");
    print_stack(buffer, "Previous stack frame");

    // Vulnerable function call - we are reading up to 0x1000 bytes into a 16 byte buffer
    fread(buffer, 1, 0x1000, pFile);

    printf("The stack after fread() call:\n");
    print_stack(buffer, "Shellcode target");

    return 0;
}

int main(int argc, char **argv) {
    FILE *pFile;

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    pFile = fopen(argv[1], "rb");
    if (NULL == pFile) {
        printf("Failed to open file: %s\n", argv[1]);
        exit(1);
    }

    vuln(pFile);

    fclose(pFile);

    return 0;
}