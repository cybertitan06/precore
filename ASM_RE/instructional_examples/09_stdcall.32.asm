BITS 32
global main

section .text

clear:
    ; prologue
    push ebp
    mov ebp, esp

    ; Clear out the registers
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    xor edi, edi
    xor esi, esi

    ; Clear out the stack so we have a clean view
    mov dword [esp+8], 0
    mov dword [esp+12], 0
    mov dword [esp+16], 0
    mov dword [esp+20], 0
    mov dword [esp+24], 0
    mov dword [esp+28], 0
    mov dword [esp+32], 0
    mov dword [esp+36], 0
    mov dword [esp+40], 0

    ; epilogue
    pop ebp
    ret

foo:
    ; prologue - create stack frame
    push ebp
    mov ebp, esp

    ; add parameters from stack
    mov eax, [ebp+8]
    add eax, [ebp+12]
    add eax, [ebp+16]

    ; clean up stack
    pop ebp
    ret 12  ; 12 bytes = 4 bytes and 3 parameters

main:
    call clear

    mov eax, 1
    mov ecx, 2
    mov edx, 3

    ; Demonstrate the stdcall calling convention

    ; let's call a function foo(5000, 3000, 229) which
    ; adds up all inputs    

    ; first, preserve the old values of eax, ecx, and edx since
    ; they can be overwritten
    push edx
    push ecx
    push eax

    push dword  229     ; right->left order
    push dword  3000
    push dword  5000
    call foo

    ; observe the value stored in eax. Should be 0x2025
    mov ecx, eax

    ; restore eax, ecx, and edx
    pop eax
    pop ecx
    pop edx

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
