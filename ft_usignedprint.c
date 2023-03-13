/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usignedprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:52:24 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/13 14:06:27 by afabbri          ###   ########.fr       */
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
	char	*str;
	int		i;

	str = NULL;
	i = ft_getunsigned(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*num;

	if (n == 0)
		return (write(1, "0", 1));
	num = ft_getitoa_unsigned(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
