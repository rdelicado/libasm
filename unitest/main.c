#include "../includes/libasm.h"
#include "../includes/test_utils.h"

extern void test_ft_strcpy(void);
extern void test_ft_strlen(void);
extern void test_ft_write(void);

void    test_strlen()
{
    printf(BLUE"\n#################### ft_strlen #####################\n"RESET);

    // Normal string
    char *s0 = "hola";

    // String void
    char *s1 = "";  

    // Very long string
    char s2[10001];
    memset(s2, 'a', 10000);
    s2[10000] = '\0';

    // String with special characters
    char *s3 = "Hello\nWorld\t!";

    // String with embedded null (stops at first '\0');
    char s4[10] = {'H','e','l','l','o','\0','W','o','r','l'};

    char *arr[] = {s0, s1, s2, s3, s4, NULL};
    int i = 0;
    while (arr[i] != NULL)
    {
        size_t len = ft_strlen(arr[i]);
        size_t orig_len = strlen(arr[i]);
        printf("\n");
        printf("result ft_strlen    (s%d): %zu\n", i, len);
        printf("result strlen       (s%d): %zu\n", i, orig_len);
        printf("_________________________________\n");
        i++;
    }
}

void    test_write()
{
    printf(BLUE"\n#################### ft_strlen #####################\n"RESET);

    ssize_t ret_ft, ret_sys;
    int saved_errno;
    char *msg = "hola\n";

    printf("\n== Test: Escritura con buffer vacío (count = 0) ==\n");
    ret_ft = ft_write(1, "hola", 0);
    ret_sys = write(1, "hola", 0);
    printf("\nft_write returned: %zd\n", ret_ft);
    printf("write returned:   %zd\n\n", ret_sys);

    printf("== Test: Escritura en stdout (fd = 1) ==\n");
    ret_ft = ft_write(1, msg, strlen(msg));
    ret_sys = write(1, msg, strlen(msg));
    printf("\nft_write returned: %zd\n", ret_ft);
    printf("write returned:   %zd\n\n", ret_sys);

    printf("== Test: Escritura en stderr (fd = 2) ==\n");
    ret_ft = ft_write(2, "error\n", 6);
    ret_sys = write(2, "error\n", 6);
    printf("\nft_write returned: %zd\n", ret_ft);
    printf("write returned:   %zd\n\n", ret_sys);

    printf("== Test: Escritura con fd inválido (fd = -1) ==\n");
    errno = 0;
    ret_ft = ft_write(-1, "hola", 4);
    saved_errno = errno;
    printf("ft_write returned: %zd, errno: %d\n", ret_ft, saved_errno);

    errno = 0;
    ret_sys = write(-1, "hola", 4);
    saved_errno = errno;
    printf("write returned:   %zd, errno: %d\n", ret_sys, saved_errno);

    printf("\n");
    printf("== Test: Escritura con buffer nulo (buf = NULL) ==\n");
    errno = 0;
    ret_ft = ft_write(1, NULL, 5);
    saved_errno = errno;
    printf("ft_write returned: %zd, errno: %d\n", ret_ft, saved_errno);

    errno = 0;
    ret_sys = write(1, NULL, 5);
    saved_errno = errno;
    printf("write returned:   %zd, errno: %d\n", ret_sys, saved_errno);
}

int main() 
{
    test_ft_strcpy();
    test_ft_strlen();
    test_ft_write();
    test_strlen();
    test_write();

    return 0;
}