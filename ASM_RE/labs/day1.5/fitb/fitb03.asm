; fitb3.asm - Created by Jered Tupik for Pre-Core 2022
;
; Here you're left more to your own devices to get an implementation going that
; satisfies what we're asking for. Best of luck getting your code to work!
[BITS 32]

section .text
global  main
extern  printf

; We're testing you on your knowledge of jmps here, so we've setup a series
; of jmp instructions that we want you to manipulate flags in order to pass
; How is up to you, just try your best to get it working!

main:

    je      test1
    jmp     jmp_fail

test1:

    js      test2
    jmp     jmp_fail

test2:

    jecxz   test3
    jmp     jmp_fail

test3:

    jg      test4
    jmp     jmp_fail

test4:

    jno      test5
    jmp     jmp_fail

test5:

    ja      test6
    jmp     jmp_fail

test6:

    jl      test7
    jmp     jmp_fail

test7:

    jb      test8
    jmp     jmp_fail

test8:

    jo      test9
    jmp     jmp_fail

test9:

    jcxz    jmp_fail
    push    good
    jmp     exit
jmp_fail:
    push    bad
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
bad:    db "Looks like one of your jumps failed somewhere", 0xA, 0
good:   db "Looks like you passed all the jumps!", 0xA, 0
