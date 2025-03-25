; Function: ft_strcmp
; int strcmp(const char *s1, const char *s2);
; Brief: function compares the two strings s1 and s2. The comparison is done using unsigned characters.
;   •  0, if the s1 and s2 are equal;
;   •  a negative value if s1 is less than s2;
;   •  a positive value if s1 is greater than s2.
; Registers:
;   - rdi: Pointer to the s1.
;   - rsi: Pointer to the s2.
;   - rax: Return an integer
; Algorithm:
;  Loop through each character until a null (0) is found.
;  Then return the difference between the two characters in rax.
; Instructions:
; test -> Compare two operands and set the flags
; je -> Jump if equal
; xor -> Bitwise XOR
; mov -> Move data from source to destination
; cmp -> Compare two operands, flags = a - b
; test -> Compare two operands, flags = a & b
; jne -> Jump if not equal
; inc -> Increment by 1
; jmp -> Jump
; movzx -> Move with zero-extend
; sub -> Subtract
; call -> Call a function
; ret -> Return
; mov dword [rax], 14 -> Store 14 in the memory address pointed by rax
; xor rax, rax -> Set rax to 0

section .text 
    global  ft_strcmp
    extern __errno_location

ft_strcmp:
    test    rdi, rdi ; Comparamos si el puntero a s1 es nulo (rdi & rdi -> ZF = 1 si es nulo)
    je      .error   ; Si es nulo, vamos a la sección de error (salta si ZF = 1)
    test    rsi, rsi ; Comparamos si el puntero a s2 es nulo
    je      .error   ; Si es nulo, vamos a la sección de error

    xor     rcx, rcx    ; index = 0

.loop:
    mov     al, byte [rdi + rcx]    ; Load character from s1[rcx]
    mov     bl, byte [rsi + rcx]    ; Load character from s2[rcx]
    cmp     al, bl                  ; Compare the two characters
    jne     .diff                   ; If not equal, calculate difference
    cmp     al, 0                   ; If al is null, end of string, end loop
    je      .end                    ; Return 0 (strings are equal)
    inc     rcx                     ; Increment index
    jmp     .loop                   ; Repeat loop

.diff:
    movzx   eax, al     ; Move the character from s1 to eax, filling with zeros to avoid sign issues
    movzx   ebx, bl      ; Move the character from s2 to ebx, filling with zeros to avoid sign issues
    sub     eax, ebx    ; Calculate the difference: eax = s1[i] - s2[i]
    ret                  ; Return the difference (in eax)

.error:
    call    __errno_location wrt ..plt  ; Get the address of errno
    mov     dword [rax], 14             ; Set EFAULT (14) to errno
    mov     rax, -1                    ; Return NULL
    ret

.end:
    xor     eax, eax    ; Return 0 (strings are equal)
    ret

    section .note.GNU-stack noalloc noexec nowrite progbits
