; Function: ft_strcpy
; char *strcpy(char *dest, const char *src);
; Brief: Copies the null-terminated string from src to dest, including the null terminator.
; Registers:
;   - rdi: Pointer to the destination buffer.
;   - rsi: Pointer to the source string.
;   - rax: Returns the destination pointer.
; Algorithm:
;   Copies each byte from src to dest until the null terminator is found.
;   Copies the null terminator, then returns dest in rax.

section .text
    global ft_strcpy

ft_strcpy
    ; Comprobar si dest o src son nulos
    test    rdi, rdi    ; Comprueba si dest en NULL
    je      .error      ; Si es NULL, salta a .error
    test    rsi, rsi    
    je      .error

    mov rax, rdi        ; guarda el puntero de dest en rax para devolverlo al final

.loop:
    mov al, byte [rsi]  ; lee un byte de rsi (dest) y almacena en ld (8 bytes)
    mov byte [rdi], al  ; Copia en rdi el valor de ld
    cmp al, 0           ; Compara si el byte es 0 (NULL)
    je  .end            ; Si es 0 finaliza
    inc rsi             ; incrementa rsi para leer el siguiente byte del src
    inc rdi             ; incremente rdi para el siguiente byte del dest
    jmp .loop           ; Salta de nuevo al inicio

.error:
    xor rax, rax        ; Devuelve 0 para indicar un error

.end:
    ret

    section .note.GNU-stack noalloc noexec nowrite progbits

    