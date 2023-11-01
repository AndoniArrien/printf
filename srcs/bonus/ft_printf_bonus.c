#include "ft_printf_bonus.h"

t_list*	ft_create_nodes(char const *s)
{
	t_list*	head;
	int		start;
	int		end;
	char	valid_conversions[] = "cspdiuxX";

	start = 0;
	end = 0;
	head = NULL;
	while (s[end])
	{
		if (!s[end+1] || s[end] == '%' || (ft_strchr(valid_conversions, s[end]) && s[start] == '%'))
		{
			t_node	*node = malloc(sizeof(t_node));
			if (!s[end+1] || s[end-1] == '%' || (ft_strchr(valid_conversions, s[end]) && s[start] == '%')) {
				node->full_content = ft_substr(s, start, end-start+1);
				end++;
			}
			else
				node->full_content = ft_substr(s, start, end-start);
			ft_lstadd_back(&head, ft_lstnew(node));
			start = end;
		}
		if (s[end])
			end++;
	}
	ft_lstiter(head, ft_print_node);
	//ft_lstiter(head, ft_fill_flags);
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
