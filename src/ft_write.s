; Function: ft_write
; Prototype: ssize_t write(int fd, const void buf[.count], size_t count);
; Brief: Writes up to 'count' bytes from the 'buf' to the file descriptor 'fd'.
;        The [.count] in buf indicates that the buffer's usable size is determined by 'count'.
; Registers:
;   - rdi: File descriptor (fd).
;   - rsi: Pointer to the buffer (buf).
;   - rdx: Number of bytes to write (count).
;   - rax: On return, holds the number of bytes written, or -1 if an error occurs.
; Other details:
;   - __errno_location is used to update the thread-specific error code on failure.
;   - Standard calling conventions apply; the stack frame preserves necessary registers.

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