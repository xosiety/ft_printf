/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:51:49 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/16 17:37:04 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, char format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_lenght += ft_printstr(va_arg(args, char *));
	else if (format == 'd')
		print_lenght += ft_printnbr(va_arg(args, int));
	else if (format == 'i')
		print_lenght += ft_printnbr(va_arg(args, int));
	else if (format == '%')
		print_lenght += ft_printpercent();
	else if (format == 'p')
		print_lenght += ft_printptr(va_arg(args, void *));
	else if (format == 'u')
		print_lenght += ft_unsignedprint(va_arg(args, unsigned int));
	else if (format == 'x')
		print_lenght += ft_printhex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		print_lenght += ft_printhex(va_arg(args, unsigned int), 'X');
	return (print_lenght);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_lenght;
	int		i;

	i = 0;
	print_lenght = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_lenght += ft_format(args, str[i]);
		}
		else
			print_lenght += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_lenght);
}
