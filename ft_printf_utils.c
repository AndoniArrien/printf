/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:18:07 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/07 13:07:45 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putptr(void const *ptr)
{

}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb >= 0)
		ft_putchar(nb + 48);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;

	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		l = ft_strlen(base);
		if (nbr >= l)
		{
			ft_putnbr_base(nbr / l, base);
			ft_putnbr_base(nbr % l, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
