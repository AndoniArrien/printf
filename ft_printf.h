/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/07 13:08:13 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
#include <stdarg.h> // va_start ,va_arg ,va_copy ,va_end

int		ft_printf(char const *s, ...);

void	ft_putchar(char c);
void	ft_putstr(char const *str);
int		ft_strlen(char *str);
void	ft_putptr(void const *ptr);
void	ft_putnbr(int nb);
void	ft_putnbr_base(int nbr, char *base);

#endif
