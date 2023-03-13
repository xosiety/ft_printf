/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:51:57 by afabbri           #+#    #+#             */
/*   Updated: 2023/03/13 15:59:08 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_printpercent(void);
int		ft_printchar(int c);
int		ft_printnbr(int n);
int		ft_printstr(char *s);
int		ft_printhex(unsigned int nb, char format);
int		ft_printptr(void *ptr);
int		ft_unsignedprint(unsigned int n);

#endif