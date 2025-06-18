/* 
Welcome to a C challenge problem! The following problem is not meant to be solved quickly nor easily.

You do not need - nor should you - compile or run the following C code. It is entirely solvable without any
external tools besides a pen and paper or some text editor.

Any knowledge you need to solve this problem is available online (no, AI doesn't understand this problem - we tried).

If you have any questions, look for Wyn or Luke to get guidance.

A full solution will be posted on Monday. Good luck!
*/



// Challenge: Determine the output of the program.

#include <elf.h>
#include <stdio.h>

static void one() {
    fprintf(stderr, "Bounce, ");
}

void two() {
    fprintf(stderr, "Up, ");
}

void three() {
    fprintf(stderr, "Left, ");
}

int main() {
    void *fn[6] = { &*one, &&one, &*two, &&two, &*three, &&three };
    char p = 0;

    goto start; end: return 0;
start:
    goto *fn[p++];
one: 
    fprintf(stderr, "wee\n");
    goto start;
two:
    fprintf(stderr, "Down\n");
    goto start;
three:
    fprintf(stderr, "Right\n");
    goto end;
}