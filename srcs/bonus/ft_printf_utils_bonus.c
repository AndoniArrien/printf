#include "ft_printf_bonus.h"

void	ft_putstr_len(char* str, int* len)
{
	int	i;

	i = 0;
	while (str[i])
		*len += write(1, &str[i++], 1);
}

void	ft_delete_node(void *content)
{
	t_node*	node = (t_node *)content;

	free(node->full_content);
	free(node);
}

void	ft_print_node(void *content)
{
	t_node*	node = (t_node *)content;

	ft_putstr_fd("[", 1);
	ft_putstr_fd(node->full_content, 1);
	ft_putstr_fd("](", 1);
	ft_putchar_fd(node->conversion, 1);
	ft_putstr_fd(") :", 1);
	if (!node->is_valid)
		ft_putstr_fd(" Node is not valid\n", 1);
	else if (!node->is_formatted)
		ft_putstr_fd(" Node is not formatted\n", 1);
	else
	{
		ft_putstr_fd("  | la ('-') = [", 1);
		ft_putnbr_fd(node->flags.left_align, 1);
		ft_putstr_fd("] | ra ('0') = [", 1);
		ft_putnbr_fd(node->flags.right_align, 1);
		ft_putstr_fd("] | pr ('.') = [", 1);
		ft_putnbr_fd(node->flags.precision, 1);
		ft_putstr_fd("] | al ('#') = [", 1);
		ft_putchar_fd(node->flags.alternate, 1);
		ft_putstr_fd("] | sg ('+') = [", 1);
		ft_putnbr_fd(node->flags.sign, 1);
		ft_putstr_fd("] | sp (' ') = [", 1);
		ft_putnbr_fd(node->flags.space, 1);
		ft_putstr_fd("] |\n", 1);
	}
}
