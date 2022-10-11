/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:38 by aarrien-          #+#    #+#             */
/*   Updated: 2022/09/30 09:48:23 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	temp = new;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (temp->next == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	temp->next = NULL;
	return (new);
}
