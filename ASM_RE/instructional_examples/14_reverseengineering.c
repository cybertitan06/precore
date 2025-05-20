/*
 * A reverse engineering example meant to be walked through with students.
 *
 * Compile with:
 * $ gcc -m64 -o 14_reverseengineering 14_reverseengineering.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _s {
    int a;
    char b;
    float c;
} myStruct;

myStruct globalMyStruct;

char *obfuscate(char *in, int n) {
    char *out = calloc(n + 1, sizeof(char));
    for (int i = 0; i < n; i++) {
        out[i] = in[i] ^ i;
    }

    return out;
}

void print_bytes(char *source, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", source[i]);
    }
}

void deobfuscate_key(char *key) {
    char *key2 = "\xde\xad\xbe\xef\xde\xad\xbe\xef";
    for (int i = 0; i < 8; i++) {
        key[i] ^= key2[i];
    }
}

char *decode(char *secret, char *key) {
    char *result = calloc(strlen(secret) + 1, sizeof(char));

    for (int i = 0; i < strlen(secret); i++) {
        result[i] = secret[i] ^ key[i % 8];
    }

    return result;
}

void dynamic_example() {
    char SECRET[15] = "\x21\x2d\x2c\x25\x30\x23\x36\x37\x2e\x23\x36\x2b\x2d\x2c\x31";
    char KEY[8] = "\x9c\xef\xfc\xad\x9c\xef\xfc\xad";
    deobfuscate_key(KEY);
    char *decoded = decode(SECRET, KEY);
}

void static_example(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        int arglen = strlen(argv[i]);
        char *obfuscated = obfuscate(argv[i], arglen);
        printf("argv[%d]: %s\n\tobfuscated: ", i, argv[i]);
        print_bytes(obfuscated, arglen);
        printf("\n");
        free(obfuscated);
    }
}

int main(int argc, char *argv[]) {
    static_example(argc, argv);
    dynamic_example();

    globalMyStruct.a = 0;
    globalMyStruct.b = 'c';
    globalMyStruct.c = 1.1f;

    return 0;
}
