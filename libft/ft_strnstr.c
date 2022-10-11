/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:32:49 by aarrien-          #+#    #+#             */
/*   Updated: 2022/09/07 10:26:17 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;

	len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && n-- != 0 && ft_strncmp(haystack, needle, len) != 0)
		haystack++;
	if (ft_strncmp(haystack, needle, len) == 0 && n + 1 >= len)
		return ((char *)haystack);
	return (NULL);
}
