; fitb1.asm - Created by Jered Tupik for Pre-Core 2022
;
; These are going to be some relatively free-form fill-in-the-blank
; labs, so best of luck!
[BITS 32]

section .text
global  main
extern  printf

; This lab is meant to be test your knowledge of NASM structures,
; so lets see if you can manage to do the following:
;
; 1) Create a structure named student that has the following fields:
;       char    name[32]
;       int     salary
;       short   year
;
; 2) Using that structure, create one with the following initial values:
;       name = "Justin"
;       salary = 0
;       year = 2023
;
; 3) Set the values during program operation to the following:
;       name = "John"
;       salary = 19
;       year = 2021
;
; Please store the structure address in EBX prior to both test sections
; and be aware that any register may be overwritten by test code.
main:

    ; DO NOT EDIT BELOW THIS - Part 2 Test Code
    push    dword [ebx+32]
    xor     eax, eax
    mov     ax, [ebx+36]
    push    eax
    push    ebx
    push    std_str
    call    printf
    add     esp, 16
    cmp     word [ebx+36], 2023
    jne     inv_year
    cmp     dword [ebx+32], 0
    jne     inv_sala
    mov     esi, ebx
    mov     edi, name1
    mov     ecx, len1
    rep     cmpsb
    cmp     ecx, 0
    jne     inv_name
    push    all_good
    call    printf
    add     esp, 4
    ; DO NOT EDIT ABOVE THIS

    ; DO NOT EDIT BELOW THIS - Part 3 Test Code
    push    dword [ebx+32]
    xor     eax, eax
    mov     ax, [ebx+36]
    push    eax
    push    ebx
    push    std_str
    call    printf
    add     esp, 16
    cmp     word [ebx+36], 2021
    jne     inv_year
    cmp     dword [ebx+32], 19
    jne     inv_sala
    mov     esi, ebx
    mov     edi, name2
    mov     ecx, len2
    rep     cmpsb
    cmp     ecx, 0
    jne     inv_name
    push    all_good
    jmp     exit 
    ; DO NOT EDIT ABOVE THIS

inv_year:
    push    bad_year
    jmp     exit
inv_sala:
    push    bad_sala
    jmp     exit
inv_name:
    push    bad_name
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80
    

section .data
name1:      db "Justin", 0
len1:       equ $-name1
name2:      db "John", 0
len2:       equ $-name2
std_str:    db "Name: %s - %d, Salary: $%d", 0xA, 0

all_good:   db "Looks like all your values match expectations", 0xA, 0
bad_name:   db "Your name doesn't match the expected result", 0xA, 0
bad_sala:   db "Your salary doesn't match the expected result", 0xA, 0
bad_year:   db "Your year doesn't match the expected result", 0xA, 0
