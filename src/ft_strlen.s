; size_t strlen(const char *s)
; Parametes: rdi = *s
; returns the number of bytes in the string pointed to by s

section .text
    global ft_strlen

ft_strlen:
    xor     rax, rax

.loop:
    cmp byte [rdi + rax], 0 ; Compara el caracter actual con '\0'
    je  .end                ; Si es '\0', termina
    inc rax                 ; Incrementa el contador en 1
    jmp .loop               ; Repite

.end:
    ret                 ; ¡Retorna al programa!

section .note.GNU-stack noalloc noexec nowrite progbits