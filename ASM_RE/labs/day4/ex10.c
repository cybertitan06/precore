
/**
 * Exercise 10 - Format Strings - Hard Mode
 * 
 * This binary has an interesting vulnerability that may take some research for you to discover.
 * Your goal is to pop a shell by somehow exploiting the printf vulnerabilities in a unique way.
 * Unlike the previous format string exercise, you will probably have a hard time simply trying
 * to leak information off the stack for a buffer overflow exploit.  Try to find what else can
 * be done utilizing format string vulnerabilities!
 *
 * Compile with:
 * $ gcc -no-pie -m64 -o ex10 ex10.c
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show_help() {
    printf("Exercise 10 - Format Strings - Hard Mode\n"
           "\n"
           "This binary has an interesting vulnerability that may take some research for you to discover.\n"
           "Your goal is to pop a shell by somehow exploiting the printf vulnerabilities in a unique way.\n"
	   "Unlike the previous format string exercise, you will probably have a hard time simply trying \n"
	   "to leak information off the stack for a buffer overflow exploit.  Try to find what else can \n"
	   "be done utilizing format string vulnerabilities!\n");
}

void parseargs(int argc, char *argv[]) {
    int opt;
    if ((opt = getopt(argc, argv, "h")) == 'h') {
        show_help();
        exit(0);
    } else if (opt > 0) {
        exit(opt);
    }
}

void vuln() {
    char input[0x100] = {0};
    puts("Enter your input: ");
    fgets(input, 0xff, stdin);

    printf(input);
    memset(input, 0, 0x100);

    puts("Enter your second input: ");
    fgets(input, 0xff, stdin);
    printf(input);
}

int main(int argc, char *argv[]) {
    parseargs(argc, argv);
    vuln();
    return 0;
}
