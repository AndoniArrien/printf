/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:38 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/04 08:55:18 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
			words++;
		while (*s != c && *s)
			s++;
		if (*s)
			s++;
	}
	return (words);
}

int	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	split = malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (split == 0)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		split[i] = malloc(sizeof(char) * (ft_word_len(s, c) + 1));
		ft_strlcpy(split[i], s, (ft_word_len(s, c) + 1));
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
