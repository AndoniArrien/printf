/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:32:49 by aarrien-          #+#    #+#             */
/*   Updated: 2022/09/07 11:35:32 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*o;

	o = s;
	while (*s)
		s++;
	if (c == 0)
		return ((char *)s);
	while (s >= o)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
