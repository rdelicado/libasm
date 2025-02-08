#include "../includes/libasm.h"
#include "test_utils.h"

void test_strcpy_basic() 
{
    print_test_name("Basic copy");
    char src[] = "Hello, world!";
    char dest[50];
    char expected[50];

    // Usar ft_strcpy
    char *result = ft_strcpy(dest, src);

    // Usar strcpy para comparar
    strcpy(expected, src);

    if (strcmp(dest, expected) != 0 || result != dest) 
    {
        print_fail("The copied string or return value is incorrect.");
        printf("Expected: \"%s\"\n", expected);
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
    } 
    else 
    {
        print_pass();
        printf("Expected: \"%s\"\n", expected);
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
    }
}

void test_strcpy_empty_string() 
{
    print_test_name("Copy empty string");
    char src[] = "";
    char dest[50];
    char expected[50];

    // Usar ft_strcpy
    char *result = ft_strcpy(dest, src);

    // Usar strcpy para comparar
    strcpy(expected, src);

    if (strcmp(dest, expected) != 0 || result != dest) 
    {
        printf("Expected: \"%s\"\n", expected);
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
        print_fail("The copied string or return value is incorrect.");
    } 
    else 
    {
        print_pass();
        printf("Expected: \"%s\"\n", expected);
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
    }
}

void test_strcpy_large_string() 
{
    print_test_name("Copy large string");
    char src[1000];
    char dest[1000];
    char expected[1000];

    // Llenar src con caracteres 'A'
    memset(src, 'A', sizeof(src) - 1);
    src[sizeof(src) - 1] = '\0';

    // Usar ft_strcpy
    char *result = ft_strcpy(dest, src);

    // Usar strcpy para comparar
    strcpy(expected, src);

    if (strcmp(dest, expected) != 0 || result != dest) 
    {
        print_fail("The copied string or return value is incorrect.");
        printf("Expected: \"%s\"\n", expected);
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
    } 
    else 
    {
        print_pass();
        printf("Expected: \"%s\"\n", expected);
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
    }
}

void test_strcpy_null_source() 
{
    print_test_name("Copy with NULL source");
    char dest[50];

    errno = 0;
    char *result = ft_strcpy(dest, NULL);

    if (result != NULL || errno != EFAULT) 
    {
        print_fail("Expected NULL return and errno = EFAULT.");
        printf("Return: %p\n", result);
        printf("Expected: NULL\n");
        printf("Errno: %d\n", errno);
        printf("Expected: EFAULT(14)\n");
    } 
    else 
    {
        print_pass();
        printf("Return: %p\n", result);
        printf("Expected: NULL\n");
        printf("Errno: %d\n", errno);
        printf("Expected: EFAULT(14)\n");
    }
}

void test_strcpy_null_destination() 
{
    print_test_name("Copy with NULL destination");
    char src[] = "Test";

    errno = 0;
    char *result = ft_strcpy(NULL, src);

    if (result != NULL || errno != EFAULT) 
    {
        print_fail("Expected NULL return and errno = EFAULT.");
        printf("Return: %p\n", result);
        printf("Expected: NULL\n");
        printf("Errno: %d\n", errno);
        printf("Expected: EFAULT(14)\n");
    } else 
    {
        print_pass();
        printf("Return: %p\n", result);
        printf("Expected: NULL\n");
        printf("Errno: %d\n", errno);
        printf("Expected: EFAULT(14)\n");
    }
}

void test_strcpy_overlap() 
{
    print_test_name("Copy overlapping memory");
    char buffer[50] = "Hello, world!";
    char *src = buffer + 7; // "world!"
    char *dest = buffer;    // "Hello, "

    // Usar ft_strcpy
    char *result = ft_strcpy(dest, src);

    // Comprobar si el resultado es correcto
    if (strcmp(dest, "world!") != 0 || result != dest) 
    {
        print_fail("Overlapping memory was not handled correctly.");
        printf("Expected: \"world!\"\n");
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
    } 
    else 
    {
        print_pass();
        printf("Expected: \"world!\"\n");
        printf("Got:      \"%s\"\n", dest);
        printf("Return:   %p\n", result);
        printf("Expected: %p\n", dest);
    }
}

// Función principal para ejecutar todas las pruebas
void test_ft_strcpy() 
{
    printf(YELLOW"\n#################### ft_strcpy #####################\n"RESET);
    
    test_strcpy_basic();
    test_strcpy_empty_string();
    test_strcpy_large_string();
    test_strcpy_null_source();
    test_strcpy_null_destination();
    test_strcpy_overlap();
}