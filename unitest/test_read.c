#include "../includes/libasm.h"
#include "test_utils.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

void test_read_from_file() 
{
    print_test_name("Read from file");
    const char *text = "Hello, libasm read!\n";
    int fd_w = open("test_read.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_w == -1) 
    {
        perror("open");
        return;
    }
    // Write text to the file
    write(fd_w, text, strlen(text));
    close(fd_w);

    int fd = open("test_read.txt", O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        return;
    }

    char buffer_ft[100] = {0};
    char buffer_std[100] = {0};

    /* Read using ft_read */
    errno = 0;
    ssize_t ret_ft = ft_read(fd, buffer_ft, sizeof(buffer_ft) - 1);
    int err_ft = errno;

    /* Reset file offset */
    lseek(fd, 0, SEEK_SET);

    /* Read using the original read */
    errno = 0;
    ssize_t ret_std = read(fd, buffer_std, sizeof(buffer_std) - 1);
    int err_std = errno;

    close(fd);
    unlink("test_read.txt");

    if (ret_ft != ret_std || strcmp(buffer_ft, buffer_std) != 0) 
    {
        print_fail("ft_read differs from the original read function.");
        printf("ft_read: ret = %zd, buffer = \"%s\", errno = %d\n", ret_ft, buffer_ft, err_ft);
        printf("read   : ret = %zd, buffer = \"%s\", errno = %d\n", ret_std, buffer_std, err_std);
    } 
    else 
    {
        print_pass();
        printf("read:       %zd bytes: \"%s\"\n", ret_std, buffer_std);
        printf("ft_read:    %zd bytes: \"%s\"\n", ret_ft, buffer_ft);
    }
}

void test_read_invalid_fd() 
{
    print_test_name("Read with invalid fd");
    char buffer[10] = {0};
    errno = 0;
    /* Call ft_read with an invalid file descriptor */
    ssize_t ret_ft = ft_read(-1, buffer, 10);
    int err_ft = errno;
    
    errno = 0;
    /* Call original read with an invalid file descriptor */
    ssize_t ret_std = read(-1, buffer, 10);
    int err_std = errno;
    
    if (ret_ft != -1 || err_ft != err_std) 
    {
        print_fail("ft_read with invalid fd did not match behavior.");
        printf("ft_read: ret = %zd, errno = %d\n", ret_ft, err_ft);
        printf("read   : ret = %zd, errno = %d\n", ret_std, err_std);
    } 
    else 
    {
        print_pass();
        printf("read:       %d\terrno = %d\n", ret_std, err_std);
        printf("ft_read:    %d\terrno = %d\n", ret_ft, err_ft);
    }
}

void test_read_null_buffer() 
{
    print_test_name("Read with null buffer");
    const char *text = "Data";
    int fd_w = open("test_null_read.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_w == -1) 
    {
        perror("open");
        return;
    }
    // Write text to the file
    write(fd_w, text, strlen(text));
    close(fd_w);

    int fd = open("test_null_read.txt", O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        return;
    }

    errno = 0;
    /* Call ft_read with a null buffer, expecting -1 and errno = EFAULT */
    ssize_t ret_ft = ft_read(fd, NULL, 10);
    int err_ft = errno;

    /* Although using a null buffer with read causes undefined behavior,
       many systems return -1 with errno set to EFAULT */
    errno = 0;
    ssize_t ret_std = read(fd, NULL, 10);
    int err_std = errno;

    close(fd);
    unlink("test_null_read.txt");

    if (ret_ft != -1 || err_ft != EFAULT) 
    {
        print_fail("ft_read with null buffer did not return -1 with errno = EFAULT.");
        printf("ft_read: ret = %zd, errno = %d\n", ret_ft, err_ft);
    } 
    else 
    {
        print_pass();
        printf("read:       %d\terrno = %d\n", ret_std, err_std);
        printf("ft_read:    %d\terrno = %d\n", ret_ft, err_ft);
    }
}

void test_read_with_zero_count() 
{
    print_test_name("Read with zero count");
    const char *text = "Data";
    int fd_w = open("test_zero_read.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_w == -1) 
    {
        perror("open");
        return;
    }
    // Write text to the file
    write(fd_w, text, strlen(text));
    close(fd_w);

    int fd = open("test_zero_read.txt", O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        return;
    }

    char buffer[50] = {0};
    errno = 0;
    /* Call ft_read with count 0 */
    ssize_t ret_ft = ft_read(fd, buffer, 0);
    int err_ft = errno;
    
    errno = 0;
    /* Call original read with count 0 */
    ssize_t ret_std = read(fd, buffer, 0);
    int err_std = errno;
    
    close(fd);
    unlink("test_zero_read.txt");

    if (ret_ft != 0) 
    {
        print_fail("ft_read with count 0 did not return 0.");
        printf("ft_read returned: %zd\n", ret_ft);
    } 
    else 
    {
        print_pass();
        printf("read:       %zd\terrno = %d\n", ret_std, err_std);
        printf("ft_read:    %zd\terrno = %d\n", ret_ft, err_ft);
    }
}

void test_ft_read() 
{
    printf(YELLOW"\n#################### ft_read #####################\n"RESET);
    test_read_from_file();
    test_read_invalid_fd();
    test_read_null_buffer();
    test_read_with_zero_count();
}