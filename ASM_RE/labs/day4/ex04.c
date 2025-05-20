/**
 * Exercise 4 - Stripped Buffer Overflow w/ Shellcode
 *
 * Building off what you've learned in the previous exercises, how do you
 * think things would change if you couldn't easily just attach a debugger
 * to the program and observe addresses from there?
 *
 * For this exercise, you'll need to figure out a way to execute your
 * shellcode when you can't use gdb to find a buffer address. 
 *
 * Compile with:
 * $ gcc -gdwarf -fno-stack-protector -z execstack -o ex04 ex04.c
 *
 * Hint: Consider what you have control over here, how you might be able
 * to redirect execution, and what information you need/how to get it
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256

void show_help() {
    printf("Exercise 4 - Stripped Buffer Overflow w/ Shellcode\n"
           "\n"
           "Building off what you've learned in the previous exercises, how do you\n"
           "think things would change if you couldn't easily just attach a debugger\n"
           "to the program and observe addresses from there?\n"
           "\n"
           "For this exercise, you'll need to figure out a way to execute your\n"
           "shellcode when you can't use gdb to find a buffer address. \n"
           "\n"
           "Hint: Consider what you have control over here, how you might be able\n"
           "to redirect execution, and what information you need/how to get it\n");
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
    
    if (getenv("DEBUG") != NULL) {
        fprintf(stdout, "buf: %p\r\n", buf);
    }
    gets(buf, argv[1]);
    fprintf(stdout, "%s", buf);
    return EXIT_SUCCESS;
}
