/**
 * Exercise 7 - Harder Stack Canaries
 *
 * Not all stack canaries will be as easy as the last one though. Why don't
 * you try your hand at GCC's own stack canaries and see whether you can
 * get shellcode execution here as well.
 *
 * For this exercise, get shellcode running that can read flag7.txt for us.
 *
 * Compile with:
 * $ gcc -gdwarf -z execstack -o ex07 ex07.c
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE   1024
#define BUF_SIZE    128

void show_help() {
    printf("Exercise 7 - Harder Stack Canaries\n"
           "\n"
           "Not all stack canaries will be as easy as the last one though. Why don't\n"
           "you try your hand at GCC's own stack canaries and see whether you can\n"
           "get shellcode execution here as well.\n"
           "\n"
           "For this exercise, get shellcode running that can read flag7.txt for us.\n");
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

void vuln_function(void) {
    char    buf[BUF_SIZE]={0};

    fprintf(stdout, "Please enter your first string\r\n");
    read(0, buf, BUFF_SIZE);
    fprintf(stdout, buf);

    fprintf(stdout, "\nPlease enter your second string\r\n");
    read(0, buf, BUFF_SIZE);
    fprintf(stdout, buf);
}

int main(int argc, char *argv[]) {
    parseargs(argc, argv);
    vuln_function();
    return EXIT_SUCCESS;
}
