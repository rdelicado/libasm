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
    mov     rax, 1      ; Número de syscall para write (1 = write)
    syscall             ; Invoca la syscall

    ; Comprobación de error: si rax es negativo, ocurrió un error.
    cmp     rax, 0
    jge     .end      ; Si rax >= 0, todo bien, salta a .end

.error:
    mov     r8, rax    ; Guarda el error (valor negativo) en r8
    neg     r8         ; r8 = -rax: error positivo (ej. EBADF = 9)
    call    __errno_location wrt ..plt  ; Obtiene la dirección de errno en rax
    mov     dword [rax], r8d             ; Asigna el error correcto a errno
    mov     rax, -1                     ; Devuelve -1 para indicar error
    ret

.end:
    ret               ; Retorna al llamador

section .note.GNU-stack noalloc noexec nowrite progbits