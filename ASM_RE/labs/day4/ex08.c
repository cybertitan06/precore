/**
 * Exercise 8 - NX and ret2libc
 *
 * While the majority of our previous exploits were able to push shellcode onto
 * the stack and gain execution from there, it turns out that people have
 * actually taken notice of this and taken appropriate countermeasures. Enter
 * the NoExecute (NX) bit, which prevents us from simply putting shellcode
 * onto the stack here.
 *
 * For this exercise, your objective is to figure out a method so we can read 
 * flag8.txt even with NX being set.
 *
 * Please make sure that ASLR is disabled:
 * $ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'
 * Compile with:
 * $ gcc -gdwarf -fno-stack-protector -m32 -o ex08 ex08.c
 *
 * Hint: ret2libc and environmental variables are likely to be your friend
 * here.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256

void show_help() {
    printf("Exercise 8 - NX and ret2libc\n"
           "\n"
           "While the majority of our previous exploits were able to push shellcode onto\n"
           "the stack and gain execution from there, it turns out that people have\n"
           "actually taken notice of this and taken appropriate countermeasures. Enter\n"
           "the NoExecute (NX) bit, which prevents us from simply putting shellcode\n"
           "onto the stack here.\n"
           "\n"
           "For this exercise, your objective is to figure out a method so we can read \n"
           "flag8.txt even with NX being set.\n"
           "\n"
           "Please make sure that ASLR is disabled:\n"
           "$ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'\n"
           "\n"
           "Hint: ret2libc and environmental variables are likely to be your friend\n"
           "here.\n");
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

    fprintf(stdout, "Who are you?\r\n");
    gets(buf);
    fprintf(stdout, "Hello %s\r\n", buf);
}

int main(int argc, char *argv[]) {
    parseargs(argc, argv);
    vuln_function();
    return EXIT_SUCCESS;
}
