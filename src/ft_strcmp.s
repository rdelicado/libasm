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

section .text 
    global  ft_strcmp
    extern __errno_location

ft_strcmp:
    test    rdi, rdi
    je      .error
    test    rsi, rsi 
    je      .error

    xor     rcx, rcx    ; indice

.loop:
    mov     al, byte [rdi + rcx]    ; Cargar caracter de s1
    mov     bl, byte [rsi + rcx]    ; Cargar caracter de s2
    cmp     al, bl                  ; Comparamos los dos caracteres
    jne     .diff                   ; Si no son iguales, calculamos diferencia
    cmp     al, 0                   ; Si al es nulo, fin de la cadena
    je      .end
    inc     rcx
    jmp     .loop

.diff:
    movzx   eax, al     ; movzx para evitar sign extension
    movzx   ebx, bl
    sub     eax, ebx    ; EAX = s1[i] - s2[i]
    ret

.error:
    call    __errno_location wrt ..plt  ; Obtiene la dirección de errno
    mov     dword [rax], 14             ; Asigna EFAULT (14) a errno
    xor     rax, rax                    ; Devuelve NULL
    ret

.end:
    xor     eax, eax    ; Retorna 0 (cadenas iguales)
    ret

    section .note.GNU-stack noalloc noexec nowrite progbits
