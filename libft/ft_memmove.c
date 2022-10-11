/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:38 by aarrien-          #+#    #+#             */
/*   Updated: 2022/09/06 18:21:50 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pd;
	char	*ps;

	pd = (char *)dst;
	ps = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (ps < pd)
	{
		i = n;
		while (i-- > 0)
			pd[i] = ps[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	return (dst);
}
