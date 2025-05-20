/**
 * Exercise 3 - Stack Buffer Overflows w/ Shellcode
 *
 * So while fread will just read in the file contents as-is, trying to
 * get shellcode into a function isn't always that conventiently. More often
 * you'll be trying to break a function which retrieves a string or something
 * and going from there. So, what do you think about trying that now?
 *
 * This exercise is intended to be an introduction to non-null, so your job
 * here is to figure out how to write shellcode capable of printing flag3.txt,
 * and exploiting this program to get your shellcode to run. Your shellcode
 * must be parsable from scanf.
 *
 * Please make sure that ASLR is disabled:
 * $ sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'
 * Compile with:
 * $ gcc -gdwarf -fno-stack-protector -z execstack -o ex03 ex03.c
 *
 * Hint: You might need to turn on core dumps to get the address figured
 * out
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256

void show_help() {
    printf("Exercise 3 - Stack Buffer Overflows w/ Shellcode\n"
           "\n"
           "So while fread will just read in the file contents as-is, trying to\n"
           "get shellcode into a function isn't always that conventiently. More often\n"
           "you'll be trying to break a function which retrieves a string or something\n"
           "and going from there. So, what do you think about trying that now?\n"
           "\n"
           "This exercise is intended to be an introduction to non-null, so your job\n"
           "here is to figure out how to write shellcode capable of printing flag3.txt,\n"
           "and exploiting this program to get your shellcode to run. Your shellcode\n"
           "must be parsable from scanf.\n"
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
    char    buf[BUF_SIZE]={0}, buf2[BUF_SIZE]={0};

    parseargs(argc, argv);

    gets(buf);
    strcpy(buf2, buf);
    memset(buf, 0, BUF_SIZE);
    fprintf(stdout, "%s\r\n", buf2);
    return EXIT_SUCCESS;
}
