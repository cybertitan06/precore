/*
 * Stack example to help illustrate how function arguments and local variables are handled on the stack
 * Compile with:
 * 32 Bit:
 * $ gcc -m32 -O0 -gdwarf-2 -fno-stack-protector -fno-pie -z execstack -z norelro -o 05_stack_args_and_vars 05_stack_args_and_vars.c
 * 64 Bit:
 * $ gcc -m64 -O0 -gdwarf-2 -fno-stack-protector -fno-pie -z execstack -z norelro -o 05_stack_args_and_vars 05_stack_args_and_vars.c
 */


int foo(int a, int b, int c) {
    int d;
    int e;

    d = a - b;
    e = b - c;

    return d + e;
}

int main(int argc, char **argv) {
    foo(3, 2, 1);

    return 0;
}
