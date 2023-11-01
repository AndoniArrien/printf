#include "ft_printf_bonus.h"

char*	ft_extract_flag_value(char flag, char* str)
{
	int		i;
	char*	value;

	i = 0;
	if (ft_strchr("-0.+ ", flag))
	{
		while (ft_isdigit(str[i]))
			i++;
		value = ft_substr(str, 0, i);
	}
	else if (flag == '#')
		value = ft_substr(str, 0, 1);
	return (value);
}

void	ft_insert_flag_value(t_node* node, char flag, char* value)
{
	if (flag == '-')
		node->flags.left_align = ft_atoi(value);
	else if (flag == '0')
		node->flags.right_align = ft_atoi(value);
	else if (flag == '.')
		node->flags.precision = ft_atoi(value);
	else if (flag == '#')
		node->flags.alternate = *value;
	else if (flag == '+')
		node->flags.sign = 1;
	else if (flag == ' ')
		node->flags.space = 1;
}

void	ft_set_flags(t_node* node, char* node_flags)
{
	int	i;
	char*	value;

	i = 0;
	while (node_flags[i])
	{
		if (ft_strchr(FLAGS, node_flags[i])) {
			if (i == (int)ft_strlen(node_flags)-1)
				break;
			value = ft_extract_flag_value(node_flags[i], &node_flags[i+1]);
			ft_insert_flag_value(node, node_flags[i], value);
			i += ft_strlen(value);
			free(value);
		}
		if (node_flags[i])
			i++;
	}
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
		if (ft_strchr(CONVERSIONS, node_content[lenght-1]))
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
