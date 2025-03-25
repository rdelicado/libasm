; Function: ft_read
; int read(int fd, void *buf, size_t count);
; Brief: Reads up to count bytes from file descriptor fd into the buffer pointed by buf.
; Registers:
;   - rdi: File descriptor
;   - rsi: Buffer pointer
;   - rdx: Count of bytes to read
;   - rax: Returns the number of bytes read on success or -1 on error
; Algorithm:
;  1. Execute syscall to perform read.
;  2. If the return value in rax is negative, an error occurred.
;  3. In case of error, convert the negative result to a positive error code 
;     and store it in errno, then return -1.
;  4. Otherwise (rax non-negative), return the number of bytes read.
section .text
    global ft_read
    extern __errno_location

ft_read:
    ; Initialize rax to 0 so that syscall can use it appropriately.
    mov     rax, 0      ; Preparamos RAX con 0 para la llamada al sistema
    syscall             ; Llamamos a la función read del sistema operativo

    ; Error checking: if rax is negative, an error occurred.
    cmp     rax, 0      ; Comparamos el valor de RAX con 0
    jge     .end        ; Si RAX es mayor o igual a 0, todo fue bien, vamos al final

.error:
    mov     r8, rax     ; Guardamos el valor negativo del error en R8
    neg     r8          ; Convertimos el valor del error a positivo (ej: -9 a 9)
    ; Obtain the address of errno and store the positive error value there
    call    __errno_location wrt ..plt  ; Obtenemos la dirección de memoria de la variable global errno
    mov     dword [rax], r8d              ; Guardamos el valor positivo del error en la variable global errno
    mov     rax, -1     ; Indicamos que hubo un error devolviendo -1
    ret                 ; Regresamos a quien llamó la función

.end:
    ret                 ; Regresamos a quien llamó la función con el número de bytes leídos en RAX

section .note.GNU-stack noalloc noexec nowrite progbits