int ft_printstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_printchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_printnbr(int n)
{
    //
}

int ft_printpercent(void)
{
    write(1, "%", 1);
    return (1);
}