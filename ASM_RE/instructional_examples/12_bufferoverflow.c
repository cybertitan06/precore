/*
 * A simple buffer overflow example.  Here we have a string pointer that contains the lower and uppercase alphabet,
 * so 52 bytes in total.  We also have a buffer intended to hold 16 bytes.  What happens when we call memcpy to copy all
 * 52 bytes of our alphabet string into buffer?
 *
 * Compile with:
 * gcc -m64 -O0 -gdwarf-2 -fno-stack-protector -no-pie -z execstack -z norelro -o 12_bufferoverflow 12_bufferoverflow.c
 */

#include <string.h>

int vuln() {
    // 52 byte string
    char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 16 byte buffer
    char buffer[0x10] = {};
    // Let's copy 52 bytes into our 16 byte buffer and see what happens
    memcpy(buffer, alphabet, 52);
    // Think about how the return instruction works - how can this be used for evil?
    return 0;
}

int main(int argc, char **argv) {
    vuln();

    return 0;
}