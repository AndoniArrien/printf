/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:18:07 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/15 11:57:32 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(va_list ptr, char const *s, int *len)
{
	if (*s == 'c')
		ft_putchar(va_arg(ptr, int), len);
	else if (*s == 's')
		ft_putstr(va_arg(ptr, char *), len);
	else if (*s == 'p')
		ft_putptr(va_arg(ptr, unsigned long long int), len);
	else if (*s == 'd')
		ft_putnbr(va_arg(ptr, int), len);
	else if (*s == 'i')
		ft_putnbr(va_arg(ptr, int), len);
	else if (*s == 'u')
		ft_putu(va_arg(ptr, unsigned int), len);
	else if (*s == 'x')
		ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef", len);
	else if (*s == 'X')
		ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF", len);
	else if (*s == '%')
		*len += write(1, "%%", 1);
}

int	ft_printf(char const *s, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_convert(ptr, &s[i + 1], &len);
			i++;
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
