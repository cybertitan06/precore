/**
 * Exercise 6 - Introduction to Stack Canaries
 *
 * Stack buffer overflows are all well and good for running our shellcode in
 * interesting programs, but as time has gone by more countermeasures have
 * been implemented to try and stop this. Stack Canaries (appropriately named
 * like their cousins in the mines) are one such mechanism of value-checking
 * to determine if a a value is overwritten (and thus the stack is bad).
 *
 * For this exercise, we've got a vulnerable function with a form of stack
 * canary checking that exits prematurely if it fails. Get your shellcode
 * to run and print out flag6.txt for us.
 *
 * Compile with:
 * $ gcc -gdwarf -fno-stack-protector -z execstack -o ex06 ex06.c
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CAN_1       0xDEADBEEF
#define CAN_2       0xBAADFEED
#define BUF_SIZE    256

void show_help() {
    printf("Exercise 6 - Introduction to Stack Canaries\n"
           "\n"
           "Stack buffer overflows are all well and good for running our shellcode in\n"
           "interesting programs, but as time has gone by more countermeasures have\n"
           "been implemented to try and stop this. Stack Canaries (appropriately named\n"
           "like their cousins in the mines) are one such mechanism of value-checking\n"
           "to determine if a a value is overwritten (and thus the stack is bad).\n"
           "\n"
           "For this exercise, we've got a vulnerable function with a form of stack\n"
           "canary checking that exits prematurely if it fails. Get your shellcode\n"
           "to run and print out flag6.txt for us.\n");
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
    int     canary1=CAN_1, canary2=CAN_2;
    char    buf[BUF_SIZE]={0};

    gets(buf);
    if (canary1 != CAN_1 || canary2 != CAN_2) {
        fprintf(stderr, "Stack smashing detected!");
        exit(-1);
    }
    fprintf(stdout, "%s\r\n", buf);
}

int main(int argc, char *argv[]) {
    parseargs(argc, argv);
    vuln_function();
    return EXIT_SUCCESS;
}
