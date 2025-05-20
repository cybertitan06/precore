/**
 * Exercise 5 - Buffer Overflow w/ printf vulnerabilities
 *
 * Oh no! Looks like they got rid of that buffer address from the last version
 * of the echo function. How are we supposed to get access to that nice
 * address now to launch our shellcode from?
 *
 * Well, that's your task for this lab. The goal is the same (read flag5.txt),
 *  but figure out a method of getting the buffer address from execution.
 *
 * Compile with:
 * $ gcc -gdwarf -fno-stack-protector -z execstack -o ex05 ex05.c
 *
 * Hint: Consider what happens when you pass a raw string into printf (look
 * up printf vulnerabilities)
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256

void show_help() {
    printf("Exercise 5 - Buffer Overflow w/ printf vulnerabilities\n"
           "\n"
           "Oh no! Looks like they got rid of that buffer address from the last version\n"
           "of the echo function. How are we supposed to get access to that nice\n"
           "address now to launch our shellcode from?\n"
           "\n"
           "Well, that's your task for this lab. The goal is the same (read flag5.txt),\n"
           " but figure out a method of getting the buffer address from execution.\n"
           "\n"
           "Hint: Consider what happens when you pass a raw string into printf (look\n"
           "up printf vulnerabilities)\n");
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

int main(int argc, char *argv[]) {
    char    buf[BUF_SIZE]={0};

    parseargs(argc, argv);
   
    gets(buf);
    fprintf(stdout, buf);
    return EXIT_SUCCESS;
}
