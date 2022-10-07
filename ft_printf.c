/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:18:07 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/07 12:45:52 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(va_list ptr, char const *s, size_t *len)
{
	if (*s == 'c')
		ft_putchar(va_arg(ptr, int));
	else if (*s == 's')
		ft_putstr(va_arg(ptr, char*));
	else if (*s == 'p')
		ft_putptr(va_arg(ptr, void*));
	else if (*s == 'd')
		ft_putnbr(va_arg(ptr, int));
	else if (*s == 'i')
		ft_putnbr(va_arg(ptr, int));
	else if (*s == 'u')
		ft_putchar('u');
	else if (*s == 'x')
		ft_putchar('x');
	else if (*s == 'X')
		ft_putchar('X');
	else if (*s == '%')
		ft_putchar('%');
	*len += 2;
}

int	ft_printf(char const *s, ...)
{
	va_list ptr;
	size_t	len;

	len = 0;
	va_start(ptr, s);
	while (s[len])
	{
		if (s[len] == '%')
		{
			ft_convert(ptr, &s[len+1], &len);
			continue;
		}
		else
			write(1, &s[len], 1);
		len++;
	}
	return (len + 1);
}
