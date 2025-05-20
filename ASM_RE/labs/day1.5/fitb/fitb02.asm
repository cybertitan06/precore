; fitb2.asm - Created by Jered Tupik for Pre-Core 2022
;
; Here you're left more to your own devices to get an implementation going that
; satisfies what we're asking for. Best of luck getting your code to work!
[BITS 32]

section .text
global  main
extern  printf

; For this lab, your task is to fill out the function cmp_num, which takes in
; two signed numbers in EBX and ECX and returns the greater of the two in EAX. 
;
; cmp_num (ebx, ecx) -> eax
cmp_num:
    ; FILL OUT THIS FUNCTION

    ret

; DO NOT EDIT BELOW THIS LINE
main:
    mov     ebx, 0
    mov     ecx, 1
    call    cmp_num
    cmp     eax, 1
    jne     bad_res
    mov     ebx, 0xFFFFFFFF
    mov     ecx, 0x42424242
    call    cmp_num
    cmp     eax, 0x42424242
    jne     bad_res
    mov     ebx, 0x7FFFFFFF
    mov     ecx, 0xFFFFFFFF
    call    cmp_num
    cmp     eax, 0x7FFFFFFF
    jne     bad_res
    mov     ebx, 0xFFFFFFFF
    mov     ecx, 0xFFFFFFFE
    call    cmp_num
    cmp     eax, 0xFFFFFFFF
    jne     bad_res
    mov     ebx, 2021
    mov     ecx, 2022
    call    cmp_num
    cmp     eax, 2022
    jne     bad_res
    
    push    good
    call    printf
    add     esp, 4
    jmp     exit

bad_res:
    push    ecx
    push    ebx
    push    eax
    push    str
    call    printf
    add     esp, 16
exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:    db "Returned %d for %d and %d", 0xA, 0
good:   db "Looks like it all checks out so far!", 0xA, 0
