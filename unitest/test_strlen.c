#include "includes/libasm.h"

// Colores ANSI para la salida
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_RESET   "\033[0m"

void print_test_name(const char *name) {
    printf(COLOR_BLUE "== Test: %s ==\n" COLOR_RESET, name);
}

void print_pass() {
    printf(COLOR_GREEN "PASS" COLOR_RESET ": Test passed successfully.\n");
}

void print_fail(const char *message) {
    printf(COLOR_RED "FAIL" COLOR_RESET ": %s\n", message);
}

void test_empty_string() {
    print_test_name("Empty string");
    const char *str = "";
    size_t result = ft_strlen(str);
    if (result != 0) {
        print_fail("Expected length of 0 for an empty string.");
    } else {
        print_pass();
    }
}

void test_single_character() {
    print_test_name("Single character string");
    const char *str = "A";
    size_t result = ft_strlen(str);
    if (result != 1) {
        print_fail("Expected length of 1 for a single character string.");
    } else {
        print_pass();
    }
}

void test_normal_string() {
    print_test_name("Normal string");
    const char *str = "Hello, world!";
    size_t result = ft_strlen(str);
    if (result != 13) {
        print_fail("Expected length of 13 for 'Hello, world!'.");
    } else {
        print_pass();
    }
}

void test_string_with_spaces() {
    print_test_name("String with spaces");
    const char *str = "This is a test string.";
    size_t result = ft_strlen(str);
    if (result != 21) {
        print_fail("Expected length of 21 for 'This is a test string.'."); 
    } else {
        print_pass();
    }
}

void test_string_with_special_characters() {
    print_test_name("String with special characters");
    const char *str = "!@#$%^&*()";
    size_t result = ft_strlen(str);
    if (result != 10) {
        print_fail("Expected length of 10 for '!@#$%^&*()'.");
    } else {
        print_pass();
    }
}

void test_long_string() {
    print_test_name("Long string");
    const char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    size_t result = ft_strlen(str);
    if (result != 51) {
        print_fail("Expected length of 51 for the given long string.");
    } else {
        print_pass();
    }
}

void test_null_terminated_in_middle() {
    print_test_name("Null terminator in middle of string");
    char str[] = "Test\0String";
    size_t result = ft_strlen(str);
    if (result != 4) {
        print_fail("Expected length of 4 because of null terminator in the middle.");
    } else {
        print_pass();
    }
}

int main() {
    test_empty_string();
    test_single_character();
    test_normal_string();
    test_string_with_spaces();
    test_string_with_special_characters();
    test_long_string();
    test_null_terminated_in_middle();

    return 0;
}