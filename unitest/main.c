#include "../includes/libasm.h"
#include "../includes/test_utils.h"

int main() 
{
    test_ft_strcmp();
    test_ft_strcpy();
    test_ft_strlen();
    test_ft_write();
    test_ft_read();
    test_ft_strdup();

    printf(YELLOW"\n#################### All Tests Completed #####################\n"RESET);
    
    return 0;
}