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

ft_strcpy:
    ; Check if dest or src are null
    test    rdi, rdi    
    je      .error      
    test    rsi, rsi    
    je      .error

    xor rcx, rcx                ; Initialize rcx (counter) to 0 (index)

.loop:
    mov al, byte [rsi + rcx]    ; Read a byte from rsi (src) and store in al
    mov byte [rdi + rcx], al    ; Copy to rdi the value of al
    cmp al, 0                   ; Check if the byte is 0 (NULL)
    je  .end                    ; If 0, end
    inc rcx                     ; Increment the index rcx to read the next byte from src
    jmp .loop                   ; Jump back to the beginning

.end:
    mov rax, rdi                ; Return the destination pointer
    ret

.error:
    call    __errno_location wrt ..plt  ; Get the address of errno
    mov     dword [rax], 14             ; Set EFAULT (14) to errno
    xor     rax, rax                    ; Return NULL
    ret

section .note.GNU-stack noalloc noexec nowrite progbits

