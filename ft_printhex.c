/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:52:06 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/07 13:56:27 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(unsigned int n)
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

static void	*ft_gethex(unsigned int n, char format)
{
	if (n >= 16)
		ft_gethex(n / 16, format);
	if (n % 16 < 10)
		ft_putchar_fd(n % 16 + '0', 1);
	else if (format == 0)
		ft_putchar_fd(n % 16 + 'a' - 10, 1);
	else
		ft_putchar_fd(n % 16 + 'A' - 10, 1);
}

int	ft_printhex(unsigned int n, char format)
{
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	ft_gethex(n, format);
	return (ft_getlen(n));
}
