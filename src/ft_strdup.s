; Function: ft_strdup
; char *ft_strdup(const char *s);
; size_t ft_strlen(const char *s);
; void *malloc(size_t size);
; Brief: Allocates enough memory for a copy of the string s, copies it, and returns the pointer.
; Registers:
;   - rdi: Source string pointer
;   - rsi: source string pointer (duplicate)
;   - rax: Return pointer (duplicate)
; Algorithm:
;  Check if the input pointer is NULL.
;  Call ft_strlen to get the length of the string.
;  Allocate memory for the duplicate string.
;  Check if malloc failed.
;  Call ft_strcpy to copy the string.
;  Return the duplicate string.
;  If the input pointer is NULL, set errno to EFAULT (14) and return NULL.
;  If malloc failed, return NULL.
;  The return value is already in rax.

section .text 
    global ft_strdup
    extern ft_strlen
    extern ft_strcpy
    extern malloc
    extern __errno_location

ft_strdup:
    ; Preserve base pointer
    push    rbp
    mov     rbp, rsp

    ; Check if the input pointer is NULL
    test    rdi, rdi
    jz      .null_input

    ; Push the source pointer onto the stack
    push    rdi

    ; Call ft_strlen, rdi remains unchanged so ft_strlen gets the same pointer
    call    ft_strlen   ; returns length in rax

    ; Add 1 for the null terminator
    inc     rax       ; rax = length + 1 ('\0' terminator)

    ; Move the size into rdi for malloc
    mov     rdi, rax  ; argument for malloc = (length+1)
    call    malloc    ; allocated pointer in rax

    ; Check if malloc failed
    test    rax, rax
    jz      .error

    ; Setup for ft_strcpy:
    ; Destination: allocated pointer (in rax)
    ; Source: original pointer (retrieved from the stack into rsi)
    ; void *ft_strcpy(void *dest, const void *src);
    ; rsi = source pointer (original string rdi stack), second argument
    ; rdi = destination pointer (allocated memory in rax), first argument
    pop     rsi      ; source pointer, recuperar el puntero original (rdi)
    mov     rdi, rax ; destination pointer
    call    ft_strcpy

    ; restore base pointer
    pop     rbp
    ret

.null_input:
    ; Set errno to EFAULT (14) and return NULL
    call    __errno_location wrt ..plt
    mov     dword [rax], 14
    xor     rax, rax
    pop     rbp
    ret

.error:
    xor     rax, rax
    pop     rbp
    ret

section .note.GNU-stack noalloc noexec nowrite progbits