#include "ft_printf.h"

static int	ft_ptrlen(unsigned long n)
{
    int	len;

    len = 1;
    while (n >= 16)
    {
        n /= 16;
        len++;
    }
    return (len);
}

static void ft_putptr(unsigned long n)
{
    if (n >= 16)
        ft_putptr(n / 16);
    if (n % 16 < 10)
        ft_putchar_fd(n % 16 + '0', 1);
    else
        ft_putchar_fd(n % 16 + 'a' - 10, 1);
}

int ft_printptr(void *ptr)
{
    /*unsigned long   n;
    int            len;

    n = (unsigned long)ptr;
    len = 0
    if (n == 0)
        return (ft_putchar_fd('0', 1));
    ft_putptr(n);
    return (ft_ptrlen(n));*/
}