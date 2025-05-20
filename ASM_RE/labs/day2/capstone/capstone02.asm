; capstone02.asm - Created by Jered Tupik for Pre-Core 2022
;
; This one is definitely going to be a bit extra from what you've been
; doing in class, so good luck!
[BITS 64]

section .text
global  main
extern  printf

; So there's this thing in computing called 64-bit. Relatively new, maybe
; you haven't heard of it. Well, it's pretty important that you expand
; your understanding to 64-bit as well if you've got the time. For that, this
; capstone tasks you with implementing several functions using the two primary
; 64 bit calling conventions, Microsoft x64 and AMD64. Good luck!
;
; As an even extra task, figure out how to be able to call these functions
; from a GCC-compiled program. Then, run that locally to find out for yourself

; factorial - Takes in one int argument and calculates the factorial
factorial_windows:

factorial_amd:

; strcmp - Takes in two string arguments and returns the index of the first
; difference.
strcmp_windows:

strcmp_amd:

main:
    push    rbp
    mov     rbp, rsp
    
    mov     rcx, 5
    sub     rsp, 32
    call    factorial_windows
    add     rsp, 32
    mov     r12, rax
    mov     rdx, rax
    mov     rsi, 5
    mov     rdi, dbg1
    call    printf
    cmp     r12, 120
    jne     fw_fail
    
    mov     rdi, 5
    call    factorial_amd
    mov     r12, rax
    mov     rdx, rax
    mov     rsi, 5
    mov     rdi, dbg1
    call    printf
    cmp     r12, 120
    jne     fa_fail

    mov     rdx, str2
    mov     rcx, str1
    sub     rsp, 32
    call    strcmp_windows
    add     rsp, 32
    mov     r12, rax
    mov     rcx, rax
    mov     rdx, str2
    mov     rsi, str1
    mov     rdi, dbg2
    call    printf
    cmp     r12, 32
    jne     sw_fail
    
    mov     rdi, str2
    mov     rsi, str1
    call    strcmp_amd
    mov     r12, rax
    mov     rcx, rax
    mov     rdx, str2
    mov     rsi, str1
    mov     rdi, dbg2
    call    printf
    cmp     r12, 32
    jne     sa_fail
    
    mov     rdi, good
    jmp     exit

fw_fail:
    mov     rdi, fw_fail_str
    jmp     exit
fa_fail:
    mov     rdi, fa_fail_str
    jmp     exit
sw_fail:
    mov     rdi, sw_fail_str
    jmp     exit
sa_fail:
    mov     rdi, sa_fail_str
    jmp     exit
exit:
    call    printf
    xor     rbx, rbx
    mov     rax, 0x3c
    syscall
    

section .data
str1:           db "This is a test of your l33t ASM skills", 0xA, 0
str2:           db "This is a test of your l33t ASM h4x0r skills", 0xA, 0

dbg1:           db "factorial(%d) is %d", 0xA, 0
dbg2:           db "strcmp(%s, %s) = %d", 0xA, 0

fw_fail_str:    db "factorial_windows didn't work out right", 0xA, 0
fa_fail_str:    db "factorial_amd didn't work out right", 0xA, 0
sw_fail_str:    db "strcmp_windows didn't work out right", 0xA, 0
sa_fail_str:    db "strcmp_amd didn't work out right", 0xA, 0
good:           db "Looks like you passed all the tests! Congrats!", 0xA, 0
