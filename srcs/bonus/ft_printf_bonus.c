#include "ft_printf_bonus.h"

void	ft_push_back(t_node** head, t_node* node)
{
	t_node*	temp;

	if (!*head)
		*head = node;
	else
	{
		temp = *head;
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
	node->next = NULL;
	return (node);
}

int	ft_format_lenght(char const *format)
{
	int i;
	char*	values;

	i = 0;
	values = "cspdiuxX";
	if (ft_strlen(format) >= 2 && format[1] == '%')
		return (2);
	while (format[i])
	{
		if (!ft_strrchr(values, format[i]))
			return (i);
		i++;
	}
	printf("lenght = %d\n", i);
	return (i);
}

t_node*	ft_create_nodes(char const *s)
{
	t_node*	head;
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
			ft_push_back(&head, ft_new_node(ft_substr(s, start, end-start)));
			start = end;
			if (!s[end])
				break;
		}
		end++;
	}
	ft_print_nodes(head);
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
