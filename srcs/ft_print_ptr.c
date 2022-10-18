/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:18:07 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/15 11:57:23 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long int ptr, int *len)
{
	*len += write(1, "0x", 2);
	if (ptr == 0)
		*len += write(1, "0", 1);
	else
		ft_putnbr_base_ptr(ptr, "0123456789abcdef", len);
}

void	ft_putnbr_base_ptr(uintptr_t nbr, char *base, int *len)
{
	if (nbr >= 16)
	{
		ft_putnbr_base_ptr(nbr / 16, base, len);
		ft_putnbr_base_ptr(nbr % 16, base, len);
	}
	else
		ft_putchar(base[nbr], len);
}
