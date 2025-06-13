/**
 * Exercise 1 - Stack Buffer Overflows
 *
 * This exercise is meant to be a simple introduction to stack buffer overflows for
 * when your goal is to execute a function that's already in the code. For this one,
 * why don't you try and figure out how to get the program to call get_flag for you?
 *
 * Please make sure that ASLR is disabled:
 * $ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'
 * Compile with:
 * $ gcc -gdwarf -no-pie -fno-stack-protector -o ex01 ex01.c
 * 


 Run the program, get it to crash reliably with cyclic(): 43 characters

 Bring the crash up in gdb, step through to just before the crash, and look at the return address

 Math out the exact offset required to overwrite the return address, change values, and gdb again

 Add shellcode in the expected input format (txt file, direct user input, whatever the program is expecting)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FLAG_SIZE 64

void get_flag(void) {
    FILE    *fp=NULL;
    char    flag[FLAG_SIZE+1]={0};

    fp = fopen("flag1.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open flag1.txt\n");
        exit(EXIT_FAILURE);
    }
    fgets(flag, FLAG_SIZE+1, fp);
    fclose(fp);
    fprintf(stdout, "%s\n", flag);
}

void show_help() {
    printf("Exercise 1 - Stack Buffer Overflows\n"
           "\n"
           "This exercise is meant to be a simple introduction to stack buffer overflows for\n"
           "when your goal is to execute a function that's already in the code. For this one,\n"
           "why don't you try and figure out how to get the program to call get_flag for you?\n"
           "\n"
           "Please make sure that ASLR is disabled:\n"
           "$ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'\n");
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
    FILE    *fp=NULL;
    char    buf[FLAG_SIZE]={0};

    parseargs(argc, argv);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file to echo>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Attempt to open argv[1]
    fp = fopen(argv[1], "rb");
    if (NULL == fp) {
        printf("Failed to open %s\n", argv[1]);
        exit(1);
    }

    // Get the length of the file so we know how much to read into our buffer
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read the contents of argv[1] into buf
    fread(buf, filesize, sizeof(char), fp);

    printf("%s", buf);
    return EXIT_SUCCESS;
}
