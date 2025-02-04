#include "includes/libasm.h"
#include <string.h>

void    test_strlen()
{
    printf("#################### ft_strlen #####################\n");

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

int main() 
{
    test_strlen();

    ft_write(1, "hola", 4);

    return 0;
}