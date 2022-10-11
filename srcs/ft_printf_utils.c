/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:18:07 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/11 09:33:36 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char const *str, int *len)
{
	if (!str)
		ft_putstr("(null)", len);
	else
	{
		while (*str)
			*len += write(1, str++, 1);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-nb, len);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else if (nb >= 0)
		ft_putchar(nb + 48, len);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *len)
{
	size_t	l;

	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', len);
	}
	l = ft_strlen(base);
	if (nbr >= l)
	{
		ft_putnbr_base(nbr / l, base, len);
		ft_putnbr_base(nbr % l, base, len);
	}
	else
		ft_putchar(base[nbr], len);
}
