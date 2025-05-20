/**
 * Exercise 9 - ROP
 *
 * Well, we've reached the last of the stack overflow exercises that have
 * been prepared for you. Now that you've touched base on a fair range of
 * stack overflows, protection techniques, and countermeasures, why don't you
 * try seeing if you can implement a ROP chain to help you out here.
 *
 * The goal is to build a ROP chain and launch a shell that can read ex9.c
 *
 * Compile with:
 * $ gcc -gdwarf -fno-stack-protector -m32 -o ex09 ex09.c -static -Wl,--whole-archive -lm -ldl -Wl,-no-whole-archive
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256

void show_help() {
    printf("Exercise 9 - ROP\n"
           "\n"
           "Well, we've reached the last of the stack overflow exercises that have\n"
           "been prepared for you. Now that you've touched base on a fair range of\n"
           "stack overflows, protection techniques, and countermeasures, why don't you\n"
           "try seeing if you can implement a ROP chain to help you out here.\n"
           "\n"
           "The goal is to build a ROP chain and launch a shell\n");
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
    FILE    *fp=NULL;

    gets(buf);
    if (strcmp("/bin/sh", buf) == 0) return;
    if (strcmp("flag9.txt", buf) == 0) return;
    fp = fopen(buf, "r");
    if (fp == NULL) return;
    while (fread(buf, sizeof(char), BUF_SIZE, fp)) {
        fprintf(stdout, "%s", buf);
        memset(buf, 0, BUF_SIZE);
    }
    fprintf(stdout, "\r\n");
    fclose(fp);
}

void system_helper(const char *cmd) {
    if (strcmp("cat flag9.txt", cmd) == 0) return;
    system(cmd);
}

int main(int argc, char *argv[]) {
    parseargs(argc, argv);
    vuln_function();
    return EXIT_SUCCESS;
}
