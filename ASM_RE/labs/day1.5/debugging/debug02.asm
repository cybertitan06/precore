; debug2.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got a small program here that should work correctly but
; just doesn't for some reason. Maybe you can see what we're doing wrong here?
[BITS 32]

section .text
global  main
extern  printf

; push and pop form the foundations for basically every program written, so
; it's important that you understand how these instructions work! This program
; is supposed to demo that, but it doesn't work quite right.

main:

    ; push and pop both manipulate the stack (and the stack register) during
    ; their operation. Because they use the stack register, we can always
    ; look at the memory ourselves to see the values
    push    str1
    mov     eax, [esp+4]
    push    eax
    call    printf
    add     esp, 8

    ; We can also pop values back into the register, which should give us back
    ; the string
    pop     eax
    push    eax
    call    printf
    add     esp, 4

    ; Now, how does the stack grow again? I think it grows upward and pop goes
    ; down?
    mov     eax, esp
    push    0
    push    1
    push    2
    mov     ebx, esp
    pop     ecx
    pop     ecx
    pop     ecx
    cmp     eax, esp
    jg      bad
    cmp     ebx, esp
    jl      bad

    push    str3
    jmp     print
bad:
    push    str2
print:
    call    printf
    add     esp, 4    
    
    ; Push/pop can deal with data of all sorts of sizes if you specify the
    ; data size, but I think it pushes 4 bytes each time
    mov     eax, esp
    push    word [w]
    sub     eax, esp
    cmp     eax, 4
    jne     bad2
       
    mov     eax, esp
    push    dword [dwdw]
    sub     eax, esp
    cmp     eax, 4
    jne     bad2
      
    push    str5
    jmp     print2
bad2:
    push    str4
print2:
    call    printf
    add     esp, 4
    
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
w:      dw 65535
dwdw:   dd 4294967295

str1:   db "Hi, welcome to the lab!", 0xA, 0
str2:   db "Hm, something isn't right", 0xA, 0
str3:   db "Yep, looks all good now", 0xA, 0
str4:   db "Wait, esp changes more than I thought", 0xA, 0
str5:   db "esp changed like I thought it would. I'm smart!", 0xA, 0
