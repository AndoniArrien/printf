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

void	ft_push_back(t_node** head, t_node* node)
{
	t_node	temp;

	temp = *head;
	if (!*head)
		head = node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

t_node*	ft_new_node(char * content)
{
	t_node* node;

	node = malloc(sizeof(t_node));
	node->full_content = content;
	return (node);
}

t_node*	ft_create_nodes(char const *s)
{
	t_node*	head;
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == '%')
		{
			ft_push_back(&head, ft_new_node(ft_substr(s, start, end-1)));
			start = end;
		}
		end++;
	}
}

int	ft_printf(char const *s, ...)
{
	va_list	ptr;
	int		len;
	int		i;

	len = 0;
	i = 0;
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
