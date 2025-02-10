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
;  4. Otherwise, return the number of bytes read.
section .text
    global ft_read
    extern __errno_location

ft_read:
    ; Initialize rax to 0 so that syscall can use it appropriately.
    mov     rax, 0      
    syscall             

    ; Error checking: if rax is negative, an error occurred.
    cmp     rax, 0
    jge     .end       ; If rax >= 0, read was successful, jump to .end

.error:
    mov     r8, rax    ; Save the negative error value in r8
    neg     r8         ; Convert error to positive (e.g., EBADF = 9)
    ; Obtain the address of errno and store the positive error value there
    call    __errno_location wrt ..plt
    mov     dword [rax], r8d             
    mov     rax, -1    ; Set return value to -1 to indicate failure
    ret

.end:
    ret              ;

section .note.GNU-stack noalloc noexec nowrite progbits