/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:51:43 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/13 15:59:17 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "../libft/libft.h"

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

int	ft_printnum(int n)
{
	int		i;
	char	*num;

	num = ft_itoa(n);
	i = ft_printstr(num);
	free(num);
	return (i);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
