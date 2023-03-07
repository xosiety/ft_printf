/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usignedprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:52:24 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/07 13:59:04 by afabbri          ###   ########.fr       */
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
	int		len;

	len = ft_getunsigned(n);
	str = malloc(sizeof(char) * (len + 1));
	return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	ft_printunsigned(unsigned int n)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_getitoa_unsigned(n);
	len = ft_getunsigned(n);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
