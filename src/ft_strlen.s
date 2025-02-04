; Function: ft_strlen
; size_t strlen(const char *s);
; Brief: Calculates the number of characters in a string.
;        The count does not include the null terminator.
; Registers:
;   - rdi: Pointer to the beginning of the string.
;   - rax: Used both as counter and to store the result.
; Algorithm:
;   Loop through each character until a null (0) is found.
;   Then return the count in rax.

section .text
    global ft_strlen

ft_strlen:
    xor     rax, rax          ; Set counter to 0

.loop:
    cmp byte [rdi + rax], 0   ; Check if current byte is null
    je  .end                ; If null, exit loop
    inc rax                 ; Increase counter
    jmp .loop               ; Continue scanning

.end:
    ret                     ; Return to caller

section .note.GNU-stack noalloc noexec nowrite progbits