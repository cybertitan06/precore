; broken3.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got some code that, for whatever reason, isn't able to compile
; correctly. We can't understand the errors, but perhaps all you big-brained
; people can figure it out and get it working? 
[BITS 32]

section .text
global  main
extern  printf


; What's really useful for conditional logic, though, is the cmp instruction.
; It's the foundation behind boolean logic, so hopefully you can help us
; figure out what's going wrong here.

main:
    cmp 1, 1 ; Let's just evaluate to true here
    je checks_out
    push    error
    jmp     exit

checks_out:
    push    good

exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
error:  db "Um... I'm not sure how you got here, but you shouldn't be.", 0xA, 0
good:   db "See? Boolean logic is cool!", 0xA, 0
