; ssize_t write(int fd, const void buf[.count], size_t count);
; Parámetros: rdi = fd, rsi = buf, rdx = count.
; Retorno: rax = bytes escritos (éxito), rax = -1 (error).

section .text
    global ft_write
    extern __errno_location

ft_write:
    ; preparar la pila
    push    rbp
    mov     rbp, rsp

    ; preparar registros para la syscall
    mov     rax, 1  ; Númerop de syscall para write
    ;mov     rsi, buffer
    ;mov     rdx, 5
    syscall

    ; Manejo de errores
    cmp     rax, 0
    jl      .error

.error:
    neg     rax
    push    rax
    call    __errno_location wrt ..plt
    pop     rcx
    mov     [rax], ecx
    mov     rax, -1
    jmp     .end

.end:
    ; --- Limpieza final ---
    add rsp, 1      ; Libera el espacio de la pila
    mov esp, ebp    ; restaurro esp
    pop rbp         ; Restaura el registro base
    ret             ; ¡Retorna al programa!

section .note.GNU-stack noalloc noexec nowrite progbits