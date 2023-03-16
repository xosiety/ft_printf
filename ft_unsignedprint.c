/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:52:24 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/16 17:34:20 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getunsigned(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_getitoa_unsigned(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_getunsigned(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (len--)
	{
		num[len] = n % 10 + '0';
		n /= 10;
	}
	return (num);
}

int	ft_unsignedprint(unsigned int n)
{
	char	*num;
	int		len;

	num = ft_getitoa_unsigned(n);
	len = ft_getunsigned(n);
	write(1, num, len);
	free(num);
	return (len);
}
