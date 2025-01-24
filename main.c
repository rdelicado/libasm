#include "includes/libasm.h"

int main() 
{
    /* printf("#################### ft_puthcar #####################\n");
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

    // Reabrimos stdout
    int fd = open("/dev/tty", O_WRONLY);
    if (fd != -1) {
        dup2(fd, 1);
        close(fd);
    }
 */

    printf("#################### ft_strlen #####################\n");
    char *s = "hola";
    ft_strlen(s);


    return 0;
}