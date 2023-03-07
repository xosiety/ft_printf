/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:51:49 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/07 14:09:28 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_lists args, char format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_lenght += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_lenght += ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_lenght += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_lenght += ft_printunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		print_lenght += ft_printhex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		print_lenght += ft_printhex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		print_lenght += ft_printchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_lenght;

	print_lenght = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_lenght += ft_formats(args, *format);
		}
		else
			print_lenght += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (print_lenght);
}
