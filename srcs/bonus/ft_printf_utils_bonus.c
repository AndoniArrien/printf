#include "ft_printf_bonus.h"

void	ft_print_node(void *content)
{
	t_node*	node = (t_node *)content;

	ft_putstr_fd("[", 1);
	ft_putstr_fd(node->full_content, 1);
	ft_putstr_fd("] ", 1);
}

void	ft_fill_flags(void *content)
{
	t_node*	node = (t_node *)content;
	char*	node_content;
	char*	flags;
	size_t	lenght;

	node_content = node->full_content;
	lenght = ft_strlen(node_content);
	if (ft_strchr(node_content, '%') == ft_strrchr(node_content, '%') && lenght > 1)
	{
		node->is_formated = 1;
		if (ft_strchr(node_content, node_content[lenght-1]))
			node->is_valid = 1;
		if (lenght > 2)
		{
			flags = ft_substr(node_content, 1, lenght-2);
			printf("Node (%s): flags = (%s)", node_content, flags);
		}
	}
}
