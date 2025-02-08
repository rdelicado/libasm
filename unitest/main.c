#include "../includes/libasm.h"
#include "../includes/test_utils.h"

extern void test_ft_strcpy(void);
extern void test_ft_strlen(void);
extern void test_ft_write(void);
extern void test_ft_strcmp(void);

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

void	test_strcpy(void)
{
    printf(BLUE"\n#################### ft_strcpy #####################\n"RESET);

	char dest[50];
    char *ret;

    printf("\n== Test: Basic copy ==\n");
    memset(dest, 0, sizeof(dest));
    errno = 0;
    ret = ft_strcpy(dest, "Hello, world!");
    printf("Source: \"%s\"\n", "Hello, world!");
    printf("Dest:   \"%s\"\n", dest);
    printf("Return: %p\n", ret);

    printf("\n== Test: Copy empty string ==\n");
    memset(dest, 'X', sizeof(dest));  // Rellenar para notar el cambio
    errno = 0;
    ret = ft_strcpy(dest, "");
    printf("Source: \"\"\n");
    printf("Dest:   \"%s\"\n", dest);
    printf("Return: %p\n", ret);

    printf("\n== Test: Copy large string ==\n");
    {
        char *src_large = malloc(10001);
        char *dest_large = malloc(10001);
        if (!src_large || !dest_large) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        memset(src_large, 'a', 10000);
        src_large[10000] = '\0';
        errno = 0;
        ret = ft_strcpy(dest_large, src_large);
        printf("Dest (first 20 chars): \"%.20s\"\n", dest_large);
        printf("String length: %zu\n", strlen(dest_large));
        printf("Return: %p\n", ret);
        free(src_large);
        free(dest_large);
    }

    printf("\n== Test: Copy with NULL source ==\n");
    memset(dest, 0, sizeof(dest));
    errno = 0;
    ret = ft_strcpy(dest, NULL);
    int saved_errno = errno;
    printf("Return: %p, errno: %d (expected errno=14)\n", ret, saved_errno);

    printf("\n== Test: Copy with NULL destination ==\n");
    errno = 0;
    ret = ft_strcpy(NULL, "Hello");
    saved_errno = errno;
    printf("Return: %p, errno: %d (expected errno=14)\n", ret, saved_errno);

    /* printf("\n== Test: Copy overlapping memory ==\n");
    {
        char overlap[50] = "Overlap test string";
        errno = 0;
        // Aunque el comportamiento es indefinido, se prueba para verificar
        ret = ft_strcpy(overlap + 3, overlap);
        printf("Buffer: \"%s\"\n", overlap);
        printf("Return: %p\n", ret);
    } */
}

void test_strcmp()
{
    printf(BLUE"\n#################### ft_strcmp #####################\n"RESET);

    int ret;

    printf("\n== Test: Basic comparison ==\n");
    ret = ft_strcmp("Hello", "Hello");
    printf("ft_strcmp(\"Hello\", \"Hello\") = %d\n", ret);
    ret = strcmp("Hello", "Hello");
    printf("strcmp(\"Hello\", \"Hello\") = %d\n", ret);

    printf("\n== Test: Different strings ==\n");
    ret = ft_strcmp("Hello", "World");
    printf("ft_strcmp(\"Hello\", \"World\") = %d\n", ret);
    ret = strcmp("Hello", "World");
    printf("strcmp(\"Hello\", \"World\") = %d\n", ret);

    printf("\n== Test: Empty string vs non-empty string ==\n");
    ret = ft_strcmp("", "Hello");
    printf("ft_strcmp(\"\", \"Hello\") = %d\n", ret);
    ret = strcmp("", "Hello");
    printf("strcmp(\"\", \"Hello\") = %d\n", ret);

    printf("\n== Test: Non-empty string vs empty string ==\n");
    ret = ft_strcmp("Hello", "");
    printf("ft_strcmp(\"Hello\", \"\") = %d\n", ret);
    ret = strcmp("Hello", "");
    printf("strcmp(\"Hello\", \"\") = %d\n", ret);

    printf("\n== Test: Both strings empty ==\n");
    ret = ft_strcmp("", "");
    printf("ft_strcmp(\"\", \"\") = %d\n", ret);
    ret = strcmp("", "");
    printf("strcmp(\"\", \"\") = %d\n", ret);

    printf("\n== Test: Strings with special characters ==\n");
    ret = ft_strcmp("Hello\n", "Hello\t");
    printf("ft_strcmp(\"Hello\\n\", \"Hello\\t\") = %d\n", ret);
    ret = strcmp("Hello\n", "Hello\t");
    printf("strcmp(\"Hello\\n\", \"Hello\\t\") = %d\n", ret);

    printf("\n== Test: Strings with embedded null characters ==\n");
    ret = ft_strcmp("Hello\0World", "Hello\0Worle");
    printf("ft_strcmp(\"Hello\\0World\", \"Hello\\0Worle\") = %d\n", ret);
    ret = strcmp("Hello\0World", "Hello\0Worle");
    printf("strcmp(\"Hello\\0World\", \"Hello\\0Worle\") = %d\n", ret);
}

int main() 
{
    test_ft_strcmp();
    test_ft_strcpy();
    test_ft_strlen();
    test_ft_write();
    test_strlen();
    test_write();
    //test_strcpy();
    //test_strcmp();

    return 0;
}