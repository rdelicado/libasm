; Function: ft_read
; int read(int fd, void *buf, size_t count);
; Brief: function reads up to count bytes from file descriptor fd into the buffer starting at buf.
; Registers:
;   - rdi: File descriptor
;   - rsi: Buffer
;   - rdx: Count
;   - rax: Return an integer
; Algorithm:
;  Loop through each character until count is reached.
;  Then return the number of characters read in rax.

section .text
    global ft_read
    extern __errno_location

ft_read:
    mov     rax, 0      ; Número de syscall para read (0 = read)
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