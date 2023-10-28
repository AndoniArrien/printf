/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/11 09:01:32 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(char const *s, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char const *str, int *len);
int		ft_strlen(char *str);
void	ft_putptr(unsigned long long int ptr, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putu(unsigned int nb, int *len);
void	ft_putnbr_base(unsigned int nbr, char *base, int *len);
void	ft_putnbr_base_ptr(uintptr_t nbr, char *base, int *len);

#endif
