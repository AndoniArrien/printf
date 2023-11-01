#include "ft_printf_bonus.h"

void	ft_init_node(t_node* node)
{
	node->is_valid = 0;
	node->is_formatted = 0;
	node->flags.left_align = 0;
	node->flags.right_align = 0;
	node->flags.precision = 0;
	node->flags.alternate = 0;
	node->flags.sign = 0;
	node->flags.space = 0;
}

t_list*	ft_create_nodes(char const *s)
{
	t_list*	head;
	int		start;
	int		end;

	start = 0;
	end = 0;
	head = NULL;
	while (s[end])
	{
		if (!s[end+1] || s[end] == '%' || (ft_strchr(CONVERSIONS, s[end]) && s[start] == '%'))
		{
			t_node	*node = malloc(sizeof(t_node));
			ft_init_node(node);
			if (!s[end+1] || s[end-1] == '%' || (ft_strchr(CONVERSIONS, s[end]) && s[start] == '%')) {
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
	ft_lstiter(head, ft_fill_node_data);
	//ft_lstiter(head, ft_print_node);
	return (head);
}