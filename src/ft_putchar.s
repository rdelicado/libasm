section .text
    global ft_putchar
    extern __errno_location  ; Necesario para manejar errno en Linux

ft_putchar:
    ; --- Prólogo (prepara el entorno) ---
    push rbp        ; Guarda el registro base anterior
    mov rbp, rsp    ; Crea un nuevo marco de pila

    ; --- Prepara la syscall write ---
    sub rsp, 1      ; Reserva 1 byte en la pila
    mov byte [rsp], dil ; Guarda el carácter (dil = parte baja de rdi)

    mov rax, 1      ; Syscall write = 1 (Linux)
    mov rdi, 1      ; stdout (pantalla)
    mov rsi, rsp    ; Puntero al carácter en la pila
    mov rdx, 1      ; Escribir 1 byte
    syscall         ; ¡Ejecuta la syscall!

    ; --- Manejo de errores ---
    cmp rax, 0      ; ¿rax < 0?
    jl .error       ; Si sí, maneja el error

    ; --- Éxito: retorna 1 ---
    mov rax, 1      ; Bytes escritos = 1
    jmp .end        ; Salta al final

.error:
    ; --- Guardar el error en errno ---
    neg rax         ; Convierte el error a positivo (ej: -13 → 13)
    push rax        ; Guarda temporalmente el código de error
    call __errno_location wrt ..plt ; Obtiene la dirección de errno
    pop rcx         ; Recupera el código de error
    mov [rax], ecx  ; Escribe el código en errno
    mov rax, -1     ; Retorna -1

.end:
    ; --- Limpieza final ---
    add rsp, 1      ; Libera el espacio de la pila
    pop rbp         ; Restaura el registro base
    ret             ; ¡Retorna al programa!

section .note.GNU-stack noalloc noexec nowrite progbits