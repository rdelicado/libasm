#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include <stdio.h>

# define BLUE    "\033[1;34m"
# define GREEN   "\033[1;32m"
# define RED     "\033[1;31m"
# define MAGENTA "\033[1;35m"
# define YELLOW  "\033[1;33m"
# define RESET   "\033[0m"

void print_test_name(const char *name);
void print_pass(void);
void print_fail(const char *message);

#endif