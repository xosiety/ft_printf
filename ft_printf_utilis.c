/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:51:43 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/07 13:59:43 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len++;
	}
	if (n >= 10)
		len += ft_printnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (len + 1);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
