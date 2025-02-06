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
    extern __errno_location

ft_strcpy
    ; Comprobar si dest o src son nulos
    test    rdi, rdi    ; Comprueba si dest en NULL
    je      .error      ; Si es NULL, salta a .error
    test    rsi, rsi    
    je      .error

    xor rcx, rcx        ; Inicializa rcx a 0 (indice)

.loop:
    mov al, byte [rsi + rcx]  ; lee un byte de rsi (dest) y almacena en ld (8 bytes)
    mov byte [rdi + rcx], al  ; Copia en rdi el valor de ld
    cmp al, 0           ; Compara si el byte es 0 (NULL)
    je  .end            ; Si es 0 finaliza
    inc rcx             ; incrementa el indice rcx para leer el siguiente byte del src
    jmp .loop           ; Salta de nuevo al inicio

.error:
    call    __errno_location wrt ..plt  ; Obtiene la dirección de errno
    mov     dword [rax], 14             ; Asigna EFAULT (14) a errno
    xor     rax, rax                    ; Devuelve NULL
    ret

.end:
    mov rax, rdi
    ret

section .note.GNU-stack noalloc noexec nowrite progbits

    