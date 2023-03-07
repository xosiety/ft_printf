/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:55:46 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/07 13:59:43 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	ft_putptr(unsigned long n)
{
	if (n >= 16)
		ft_putptr(n / 16);
	if (n % 16 < 10)
		ft_putchar_fd(n % 16 + '0', 1);
	else
		ft_putchar_fd(n % 16 + 'a' - 10, 1);
}

int	ft_printptr(void *ptr)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	ft_putptr(n);
	return (ft_ptrlen(n));
}
