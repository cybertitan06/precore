/**
 * Exercise 2 - Stack Buffer Overflows w/ Shellcode
 *
 * Awww, it looks like this exercise doesn't have convenient access to that
 * function that would just print the flag file for us. Well, in that case
 * why don't you try figuring out how we can leverage a buffer overflow to
 * still have that code anyways?
 *
 * This exercise is intended to be an introduction to shellcode, so your job
 * here is to figure out how to write shellcode capable of printing flag2.txt,
 * and exploiting this program to get your shellcode to run.
 *
 * Please make sure that ASLR is disabled:
 * $ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'
 * Compile with:
 * $ gcc -gdwarf -no-pie -fno-stack-protector -z execstack -o ex02 ex02.c
 *
 * Hint: You might need to turn on core dumps to get the address figured
 * out
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1000

void show_help() {
    printf("Exercise 2 - Stack Buffer Overflows w/ Shellcode\n"
           "\n"
           "Awww, it looks like this exercise doesn't have convenient access to that\n"
           "function that would just print the flag file for us. Well, in that case\n"
           "why don't you try figuring out how we can leverage a buffer overflow to\n"
           "still have that code anyways?\n"
           "\n"
           "This exercise is intended to be an introduction to shellcode, so your job\n"
           "here is to figure out how to write shellcode capable of printing flag2.txt,\n"
           "and exploiting this program to get your shellcode to run.\n"
           "\n"
           "Please make sure that ASLR is disabled:\n"
           "$ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'\n"
           "\n"
           "Hint: You might need to turn on core dumps to get the address figured out\n");
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
    FILE    *fp=NULL;

    parseargs(argc, argv);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    fread(buf, 0x1000, sizeof(char), fp);
    fprintf(stdout, "%s\n", buf);
    return EXIT_SUCCESS;
}
