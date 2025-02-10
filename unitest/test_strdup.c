#include "../includes/libasm.h"
#include "test_utils.h"

void test_strdup_basic() 
{
    print_test_name("Basic strdup");
    const char *original = "Hello, world!";
    char *dup = ft_strdup(original);
    if (!dup) 
    {
        print_fail("ft_strdup returned NULL for a valid string.");
        return;
    }
    if (strcmp(original, dup) != 0 || original == dup) 
    {
        print_fail("ft_strdup did not duplicate the string correctly.");
        printf("Original: \"%s\"\n", original);
        printf("Duplicate: \"%s\"\n", dup);
        free(dup);
        return;
    } 
    else 
    {
        print_pass();
        printf("Original: \"%s\"\n", original);
        printf("Duplicate: \"%s\"\n", dup);
    }
    free(dup);
}

void test_strdup_empty_string() 
{
    print_test_name("Empty string strdup");
    const char *original = "";
    char *dup = ft_strdup(original);
    if (!dup) 
    {
        print_fail("ft_strdup returned NULL for an empty string.");
        return;
    }
    if (strcmp(original, dup) != 0) 
    {
        print_fail("ft_strdup did not handle the empty string correctly.");
        printf("Original: \"%s\"\n", original);
        printf("Duplicate: \"%s\"\n", dup);
        free(dup);
        return;
    } 
    else 
    {
        print_pass();
        printf("Original: \"%s\"\n", original);
        printf("Duplicate: \"%s\"\n", dup);
    }
    free(dup);
}

void test_strdup_null_pointer() 
{
    print_test_name("Null pointer strdup");
    errno = 0;
    char *dup = ft_strdup(NULL);
    if (dup != NULL || errno != EFAULT) 
    {
        print_fail("Expected NULL return and errno = EFAULT for null pointer.");
        printf("Return: %p\n", dup);
        printf("Errno: %d (expected: %d)\n", errno, EFAULT);
    } 
    else 
    {
        print_pass();
        printf("Returned NULL and errno = %d as expected.\n", errno);
    }
}

void test_ft_strdup() 
{
    printf(YELLOW"\n#################### ft_strdup #####################\n"RESET);
    test_strdup_basic();
    test_strdup_empty_string();
    test_strdup_null_pointer();
}