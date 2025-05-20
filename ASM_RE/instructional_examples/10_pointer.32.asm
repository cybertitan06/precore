BITS 32
global main

main:
    ; Zero out our registers
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx

    ; Clear out some space on the stack
    mov dword [esp+4], 0
    mov dword [esp+8], 0
    mov dword [esp+12], 0
    mov dword [esp+16], 0
    mov dword [esp+20], 0
    mov dword [esp+24], 0

    ; pointers are variables that contain the address of other variables
    push 0x100      ; what value is now at the address eax has?
    mov eax, esp    ; esp is the stack "pointer", and references the
                    ; current stack location
    mov dword ebx, [eax]    ; ebx now holds the value eax was "pointing at"
    mov dword [eax], 0x2025 ; eax now points to the value 2025
    pop ecx                 ; ecx now has the value 2025
    sub esp, 4

    ; so long as its a valid region of memory with permissions, a pointer can
    ; be used for read/write
    mov dword [eax], 0x23   ; the value in memory still changes even though
                            ; we popped the stack


    ; you can do math on pointers like any other variable
    add eax, 3

    ; and use those new values to change other addresses

    mov byte [eax], 0xff    ; observe that the 3rd byte is now 0xff
    sub eax, 2
    mov word [eax], 0x7fff  ; 2rd + 1st = 0x7fff

    ; lea is convenient to get the address of data/variables
    lea ebx, [eax-1]    ; ebx should be eax - 1
    mov dword [ebx], 0  ; clear the whole word
    
nothing:
; A whole lot of nothing so we keep the bottom of our screen clean
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
