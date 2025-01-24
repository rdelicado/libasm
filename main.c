#include "includes/libasm.h"
#include <unistd.h>    // Para close()
#include <errno.h>     // Para errno
#include <stdio.h>     // Para printf() y perror()

int main() {
    // --------------------- Caso exitoso ---------------------
    ft_putchar('H');
    ft_putchar('i');
    ft_putchar('\n');

    // --------------------- Caso de error ---------------------
    // Cerramos stdout (descriptor 1) para forzar un error
    close(1);

    // Intentamos escribir en un descriptor cerrado (debería fallar)
    int result = ft_putchar('E');
    
    if (result == -1) {
        fprintf(stderr, "¡Error manejado correctamente!\n");
        fprintf(stderr, "Código de error (errno): %d\n", errno);
        perror("Mensaje del sistema");
    }

    return 0;
}