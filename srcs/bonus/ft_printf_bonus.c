#include "ft_printf_bonus.h"

void	ft_print_node(void *content)
{
	t_node *node = (t_node *)content;

	printf("Node : %s\n", node->full_content);
}

t_list*	ft_create_nodes(char const *s)
{
	t_list*	head;
	int		start;
	int		end;

	start = 0;
	end = 0;
	head = NULL;
	
	while (1)
	{
		if (s[end] == '%' || !s[end])
		{
			if (end != 0 && s[end-1] == '%')
				end++;
			t_node	*node = malloc(sizeof(t_node));
			node->full_content = ft_substr(s, start, end-start);
			ft_lstadd_back(&head, ft_lstnew(node));
			start = end;
			if (!s[end])
				break;
		}
		end++;
	}
	ft_lstiter(head, ft_print_node);
	return (head);
}

int	ft_printf(char const *s, ...)
{
	va_list	ptr;
	int		len;
	//int		i;

	len = 0;
	//i = 0;
	va_start(ptr, s);
	ft_create_nodes(s);
	va_end(ptr);
	return (len);
}
