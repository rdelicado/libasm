#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	char	res;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	res = (n % 10) + '0';
	write(1, &res, 1);
}

int ft_atoi(const char *ptr)
{
    // "1"
    int res = 0;
    int i = 0;
    while (ptr[i++]) {
        res = ptr[i] + '0' - 47;
    }
    return res;
}

int ft_atoi_base(const char *str, int str_base) {
    if (str_base >= 2 && str_base <= 16) {
        write (1, "base correcta\n", 14);
        int res_str = ft_atoi(str);
        printf("string: %d\n", res_str);
    }
    else {
        write (1, "base incorrecta\n", 16);
    }
}

int main()
{
    ft_atoi_base("6", 3);
    return 0;
}