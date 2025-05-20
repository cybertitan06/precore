; fitb4.asm - Created by Jered Tupik for Pre-Core 2022
;
; Here you're left more to your own devices to get an implementation going that
; satisfies what we're asking for. Best of luck getting your code to work!
[BITS 32]

section .text
global  main
extern  printf

; Hope you're ready for some push/pop fun. To see if you understand what's
; going on under the hood with push/pop (at a high level), your job for this
; lab is to manually implement push/pop as 'functions', which we'll
; be calling to verify matches expectations. Good luck!

; my_push function. Expects input to be in EAX and the return address in EBX
; Should emulate push and add to the stack. Assume 4 byte input
my_push:

; my_pop function. Should pop the top object off the stack and store the
; result in EAX, then return to EBX. Assume 4 byte output
my_pop:

main:

    mov     eax, 0x00000000
    mov     ebx, push1
    jmp     my_push
push1:
    pop     eax
    cmp     eax, 0x00000000
    jne     push_fail
    mov     eax, 0x0000FF00
    mov     ebx, push2
    jmp     my_push
push2:
    mov     eax, 0x00FF0000
    mov     ebx, push3
    jmp     my_push
push3:
    pop     eax
    cmp     eax, 0x00FF0000
    jne     push_fail
    pop     eax
    cmp     eax, 0x0000FF00
    jne     push_fail 

    push    0x00000000
    push    0x0000FF00
    push    0x00FF0000
    mov     ebx, pop1
    jmp     my_pop
pop1:
    cmp     eax, 0x00FF0000
    jne     pop_fail
    pop     eax
    mov     ebx, pop2
    jmp     my_pop
pop2:
    cmp     eax, 0x00000000
    jne     pop_fail
    push    0xAFAFAFAF
    pop     eax
    mov     ebx, pop3
    jmp     my_pop
pop3:
    cmp     eax, 0xAFAFAFAF
    je      pop_fail
    push    good
    jmp     exit

push_fail:
    push    bad_push
    jmp     exit
pop_fail:
    push    bad_pop
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
bad_push:   db "Your push function isn't matching our expectations.", 0xA, 0
bad_pop:    db "Your pop function isn't matching our expectations.", 0xA, 0
good:       db "Looks like everything matches. Hopefully you undertand what's going on with push/pop now!", 0xA, 0
