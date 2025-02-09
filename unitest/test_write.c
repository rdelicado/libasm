#include "../includes/libasm.h"
#include "test_utils.h"

void test_write_to_stdout() 
{
    print_test_name("Write to stdout");
    ssize_t ret = ft_write(1, "Test stdout\n", 12);
    if (ret != 12) 
    {
        print_fail("Expected 12 bytes, but wrote fewer.");
        printf("Returned: %zd\n", ret);
    } 
    else 
    {
        print_pass();
        printf("Returned: %zd\n", ret);
        printf("Expected: %d\n", 12);
    }
}

void test_write_to_stderr() 
{
    print_test_name("Write to stderr");
    ssize_t ret = ft_write(2, "Test stderr\n", 12);
    if (ret != 12) 
    {
        print_fail("Expected 12 bytes, but wrote fewer.");
        printf("Returned: %zd\n", ret);
    } 
    else 
    {
        print_pass();
        printf("Returned: %zd\n", ret);
        printf("Expected: %d\n", 12);
    }
}

void test_write_to_file() 
{
    print_test_name("Write to file");
    int fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) 
    {
        perror("open");
        return;
    }

    ssize_t ret = ft_write(fd, "Hello, file!\n", 13);
    close(fd);

    if (ret != 13) 
    {
        print_fail("Expected 13 bytes, but wrote fewer.");
        printf("Returned: %zd\n", ret);
    } 
    else 
    {
        FILE *file = fopen("test.txt", "r");
        if (!file) 
        {
            perror("fopen");
            print_fail("Could not open the file to verify its content.");
            return;
        }

        char buffer[50];
        ssize_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, file);
        buffer[bytesRead] = '\0';   
        fclose(file);

        if (strcmp(buffer, "Hello, file!\n") != 0) 
        {
            print_fail("File content does not match the expected output.");
            printf("Expected: 'Hello, file!\\n'\n");
            printf("Returned: '%s'\n", buffer);
        } 
        else 
        {
            print_pass();
            printf("Expected: 'Hello, file!\\n'\n");
            printf("Returned: '%s'\n", buffer);
        }
    }
    unlink("test.txt");
}

void test_write_with_zero_count() 
{
    print_test_name("Write with zero count");
    ssize_t ret = ft_write(1, "This should not be written", 0);
    if (ret != 0) 
    {
        print_fail("Expected 0 bytes, but wrote more.");
        printf("Returned: %zd\n", ret);
    } 
    else 
    {
        print_pass();
        printf("Returned: %zd\n", ret);
        printf("Expected: %d\n", 0);
    }
}

void test_write_with_invalid_fd() 
{
    print_test_name("Write with invalid file descriptor");
    errno = 0;
    ssize_t ret = ft_write(-1, "Invalid FD", 9);
    ssize_t original = write(-1, "Invalid FD", 9);
    if (ret != -1 || errno != EBADF) 
    {
        print_fail("Expected -1 and errno = EBADF, but got a different result.");
        printf("Returned: %zd\terrno: %d\n", ret, errno);
    }
    else 
    {
        print_pass();
        printf("Returned: %zd\terrno: %d\n", ret, errno);
        printf("Original: %zd\terrno: %d\n", original, errno);
    }
}

void test_write_with_null_buffer() 
{
    print_test_name("Write with null buffer");
    errno = 0;
    ssize_t ret = ft_write(1, NULL, 5);
    if (ret != -1 || errno != EFAULT) 
    {
        print_fail("Expected -1 and errno = EFAULT, but got a different result.");
        printf("Returned: %zd\terrno: %d\n", ret, errno);
    } 
    else 
    {
        print_pass();
        ssize_t original = write(-1, "Invalid FD", 9);
        printf("Original: %zd\terrno: %d\n", original, errno);
        printf("Returned: %zd\terrno: %d\n", ret, errno);
    }
}

void test_write_partial() 
{
    print_test_name("Partial write (pipe)");
    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) 
    {
        perror("pipe");
        return;
    }

    ssize_t ret = ft_write(pipe_fds[1], "1234567890", 10);
    close(pipe_fds[1]);

    if (ret <= 0 || ret > 10) 
    {
        print_fail("Partial write did not work as expected.");
        printf("Returned: %zd\n", ret);
    } 
    else 
    {
        print_pass();
        printf("Original: %d\n", 10);
        printf("Returned: %zd\n", ret);
    }

    close(pipe_fds[0]);
}

void test_ft_write() 
{
    printf(YELLOW"\n#################### ft_write #####################\n"RESET);
    test_write_to_stdout();
    test_write_to_stderr();
    test_write_to_file();
    test_write_with_zero_count();
    test_write_with_invalid_fd();
    test_write_with_null_buffer();
    test_write_partial();
}