/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:52:06 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/13 14:05:13 by afabbri          ###   ########.fr       */
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

static void	*ft_gethex(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		ft_gethex(nb / 16, format);
		ft_gethex(nb % 16, format);
	}
	else if (nb > 9)
	{
		if (format == 'x')
			ft_putchar_fd((nb - 10 + 'a'), 1);
		if (format == 'X')
			ft_putchar_fd((nb - 10 + 'A'), 1);
	}
	else
		ft_putchar_fd((nb + '0'), 1);
	return (0);
}

int	ft_printhex(unsigned int nb, char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_gethex(nb, format);
	return (ft_getlen(nb));
}
