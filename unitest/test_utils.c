#include "test_utils.h"

void print_test_name(const char *name) 
{
    printf(MAGENTA "== Test: %s ==\n" RESET, name);
}

void print_pass(void) 
{
    printf(GREEN "PASS" RESET ": Test passed successfully.\n");
}

void print_fail(const char *message) 
{
    printf(RED "FAIL" RESET ": %s\n", message);
}