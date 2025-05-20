BITS 32
global main

; Declare used libc functions
extern printf

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

main:
    call clear

    mov eax, 1
    mov ecx, 2
    mov edx, 3

    ; Demonstrate the cdecl calling convention

    ; As an example, let's setup the stack to call
    ; printf(msg, 2027) since GCC uses cdecl

    ; eax, ecx, and edx are volatile and need to be saved
    push edx
    push ecx
    push eax
    
    ; parameters are pushed right->left
    push        2027
    push dword  msg

    ; call the function
    call printf

    ; cleanup the stack. Observe the values of eax, ecx, and edx as well as
    ; the stack state.
    add esp, 8

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

section .data
msg : db "Hello Class of %d", 0xA, 0
