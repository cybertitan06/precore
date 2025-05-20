; fitb2.asm - Created by Jered Tupik for Pre-Core 2022
;
; These are going to be some relatively free-form fill-in-the-blank
; labs, so best of luck!
[BITS 32]

section .text
global  main
extern  printf

; Welp, this one is gonna be a bit of a ringer. Here, we're giving you a couple
; of different functions, and your job is going to be to properly setup the
; calling structure and cleanup actions for each one of them based off their
; respective standard, as well as getting the prologue and epilogue for each 
; function in shape (remember to properly restore registers!)

; fibonacci - Takes in one int argument and calculates the fibonacci number
; NOTE: Don't give this thing large nums, it'll easily consume all your CPU
fibonacci_cdecl:
    ; PROLOGUE START
    ; PROLOGUE END
    mov     eax, [ebp+8]
    cmp     eax, 1
    je      f_ret_c
    jl      f_ret_c
    dec     eax
    push    eax
    call    fibonacci_cdecl
    add     esp, 4
    mov     [ebp-4], eax
    mov     eax, [ebp+8]
    sub     eax, 2
    push    eax
    call    fibonacci_cdecl
    add     esp, 4
    add     eax, [ebp-4]
f_ret_c:
    ; EPILOGUE START
    ; EPILOGUE END

fibonacci_optilink:
    ; PROLOGUE START
    ; PROLOGUE END
    mov     [ebp-4], eax
    cmp     eax, 1
    je      f_ret_o
    jl      f_ret_o
    dec     eax
    call    fibonacci_optilink
    mov     [ebp-8], eax
    mov     eax, [ebp-4]
    sub     eax, 2
    call    fibonacci_optilink
    add     eax, [ebp-8]
f_ret_o:
    ; EPILOGUE START
    ; EPILOGUE END

fibonacci_stdcall:
    ; PROLOGUE START
    ; PROLOGUE END
    mov     eax, [ebp+8]
    cmp     eax, 1
    je      f_ret_s
    jl      f_ret_s
    dec     eax
    push    eax
    call    fibonacci_stdcall
    mov     [ebp-4], eax
    mov     eax, [ebp+8]
    sub     eax, 2
    push    eax
    call    fibonacci_stdcall
    add     eax, [ebp-4]
f_ret_s:
    ; EPILOGUE START
    ; EPILOGUE END

; inc_series_5 - Takes in a set of 5 numbers and determines if the parameters
; are passed in increasing order. If so, returns a 1, else returns a 0

inc_series_5_cdecl:
    ; PROLOGUE START
    ; PROLOGUE END
    mov     eax, 0
    mov     ecx, [ebp+8]
    cmp     ecx, [ebp+12]
    jge     is5_ret_c
    mov     ecx, [ebp+12]
    cmp     ecx, [ebp+16]
    jge     is5_ret_c
    mov     ecx, [ebp+16]
    cmp     ecx, [ebp+20]
    jge     is5_ret_c
    mov     ecx, [ebp+20]
    cmp     ecx, [ebp+24]
    jge     is5_ret_c
    mov     eax, 1
is5_ret_c:
    ; EPILOGUE START
    ; EPILOGUE END

inc_series_5_optilink:
    ; PROLOGUE START
    ; PROLOGUE END
    cmp     eax, ecx
    jge     is5_ret_o_bad
    cmp     ecx, edx
    jge     is5_ret_o_bad
    cmp     edx, [ebp+8]
    jge     is5_ret_o_bad
    mov     eax, [ebp+8]
    cmp     eax, [ebp+12]
    jge     is5_ret_o_bad
    mov     eax, 1
    jmp     is5_ret_o
is5_ret_o_bad:
    mov     eax, 0
is5_ret_o:
    ; EPILOGUE START
    ; EPILOGUE END

inc_series_5_stdcall:
    ; PROLOGUE START
    ; PROLOGUE END
    mov     eax, 0
    mov     ecx, [ebp+8]
    cmp     ecx, [ebp+12]
    jge     is5_ret_s
    mov     ecx, [ebp+12]
    cmp     ecx, [ebp+16]
    jge     is5_ret_s
    mov     ecx, [ebp+16]
    cmp     ecx, [ebp+20]
    jge     is5_ret_s
    mov     ecx, [ebp+20]
    cmp     ecx, [ebp+24]
    jge     is5_ret_s
    mov     eax, 1
is5_ret_s:
    ; EPILOGUE START
    ; EPILOGUE END

main:

    push    fc
    
    ; Setup to call fibonacci (0)
    call    fibonacci_cdecl
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    
    ; Setup to call fibonacci (1)
    call    fibonacci_cdecl
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 1
    jne     test_fail
    
    ; Setup to call fibonacci (10)
    call    fibonacci_cdecl
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 55
    jne     test_fail
    push    good_fmt
    call    printf
    add     esp, 8
    
    push    fo
    
    ; Setup to call fibonacci (0)
    call    fibonacci_optilink
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    
    ; Setup the call fibonacci (1)
    call    fibonacci_optilink
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 1
    jne     test_fail
    
    ; Setup the call fibonacci (10)
    call    fibonacci_optilink
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 55
    jne     test_fail
    push    good_fmt
    call    printf
    add     esp, 8

    push    fst
    
    ; Setup the call fibonacci (0)
    call    fibonacci_stdcall
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    
    ; Setup the call fibonacci (1)
    call    fibonacci_stdcall
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 1
    jne     test_fail
    
    ; Setup the call fibonacci (10)
    call    fibonacci_stdcall
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 55
    jne     test_fail
    push    good_fmt
    call    printf
    add     esp, 8

    push    is5c
    
    ; Setup the call for inc_series_5(0, 0, 0, 0, 0)
    call    inc_series_5_cdecl
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    
    ; Setup the call for inc_series_5(1, 2, 3, 4, 5)
    call    inc_series_5_cdecl
    ; Cleanup the result of the function call (if necessary)
    
    cmp     eax, 1
    jne     test_fail

    ; Setup the call for inc_series_5(4, 3, 2, 1, 0)
    call    inc_series_5_cdecl
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    push    good_fmt
    call    printf
    add     esp, 8

    push    is5o
    
    ; Setup the call for inc_series_5(0, 0, 0, 0, 0)
    call    inc_series_5_optilink
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    
    ; Setup the call for inc_series_5(1, 2, 3, 4, 5)
    call    inc_series_5_optilink
    ; Cleanup the result of the function call (if necessary)
    
    cmp     eax, 1
    jne     test_fail

    ; Setup the call for inc_series_5(4, 3, 2, 1, 0)
    call    inc_series_5_optilink
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    push    good_fmt
    call    printf
    add     esp, 8
    
    push    is5s
    
    ; Setup the call for inc_series_5(0, 0, 0, 0, 0)
    call    inc_series_5_stdcall
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    
    ; Setup the call for inc_series_5(1, 2, 3, 4, 5)
    call    inc_series_5_stdcall
    ; Cleanup the result of the function call (if necessary)
    
    cmp     eax, 1
    jne     test_fail

    ; Setup the call for inc_series_5(4, 3, 2, 1, 0)
    call    inc_series_5_stdcall
    ; Cleanup the result of the function call (if necessary)

    cmp     eax, 0
    jne     test_fail
    push    good_fmt
    call    printf
    add     esp, 8
    jmp     exit
 
test_fail:
    push    bad_fmt
    call    printf
    add     esp, 8
exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80
    

section .data
good_fmt    db "Looks like %s is good", 0xA, 0
bad_fmt     db "Something is up with %s", 0xA, 0
fc:         db "fibonacci_cdecl", 0
fo:         db "fibonacci_optilink", 0
fst:        db "fibonacci_stdcall", 0
is5c:       db "is_series_5_cdecl", 0
is5o:       db "is_series_5_optilink", 0
is5s:       db "is_series_5_stdcall", 0
