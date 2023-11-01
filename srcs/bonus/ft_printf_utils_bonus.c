#include "ft_printf_bonus.h"

int		ft_is_valid_conversion(char c)
{
	char	valid_conversions[] = "cspdiuxX";

	if (ft_strchr(valid_conversions, c))
		return (1);
	return (0);
}

void	ft_print_node(void *content)
{
	t_node*	node = (t_node *)content;

	ft_putstr_fd("[", 1);
	ft_putstr_fd(node->full_content, 1);
	ft_putstr_fd("] :", 1);
	if (!node->is_valid)
		ft_putstr_fd(" Node is not valid\n", 1);
	else if (!node->is_formatted)
		ft_putstr_fd(" Node is not formatted\n", 1);
	else
	{
		ft_putstr_fd(" la = ", 1);
		ft_putstr_fd(ft_itoa(node->flags.left_align), 1);
		ft_putstr_fd(" ra = ", 1);
		ft_putstr_fd(ft_itoa(node->flags.right_align), 1);
		ft_putstr_fd(" pr = ", 1);
		ft_putstr_fd(ft_itoa(node->flags.precision), 1);
		ft_putstr_fd(" al = ", 1);
		ft_putstr_fd(ft_itoa(node->flags.alternate), 1);
		ft_putstr_fd(" sg = ", 1);
		ft_putstr_fd(ft_itoa(node->flags.sign), 1);
		ft_putstr_fd(" sp = ", 1);
		ft_putstr_fd(ft_itoa(node->flags.space), 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_set_flags(t_node* node, char* node_flags)
{
	(void)node_flags;
	(void)node;
	printf("setting node flags");
}

void	ft_fill_node_data(void *content)
{
	t_node*	node = (t_node *)content;
	char*	node_content;
	char*	node_flags;
	size_t	lenght;

	node_content = node->full_content;
	lenght = ft_strlen(node_content);
	if (ft_strchr(node_content, '%') && ft_strchr(node_content, '%') == ft_strrchr(node_content, '%') && lenght > 1)
	{
		node->is_formatted = 1;
		if (ft_is_valid_conversion(node_content[lenght-1]))
			node->is_valid = 1;
		if (lenght > 2)
		{
			node_flags = ft_substr(node_content, 1, lenght-2);
			ft_set_flags(node, node_flags);
			free(node_flags);
		}
	}
	else
		node->is_valid = 1;
}
