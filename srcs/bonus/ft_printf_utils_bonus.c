#include "ft_printf_bonus.h"

int		ft_is_valid_conversion(char c)
{
	char	valid_conversions[] = "cspdiuxX";

	if (ft_strchr(valid_conversions, c))
		return (1);
	return (0);
}

int		ft_is_valid_flag(char c)
{
	char	valid_flags[] = "-0.#+ ";

	if (ft_strchr(valid_flags, c))
		return (1);
	return (0);
}

//void	ft_delete_node(void *content)

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
		ft_putstr_fd("  | la ('-') = [", 1);
		ft_putstr_fd(ft_itoa(node->flags.left_align), 1);
		ft_putstr_fd("] | ra ('0') = [", 1);
		ft_putstr_fd(ft_itoa(node->flags.right_align), 1);
		ft_putstr_fd("] | pr ('.') = [", 1);
		ft_putstr_fd(ft_itoa(node->flags.precision), 1);
		ft_putstr_fd("] | al ('#') = [", 1);
		ft_putstr_fd(ft_itoa(node->flags.alternate), 1);
		ft_putstr_fd("] | sg ('+') = [", 1);
		ft_putstr_fd(ft_itoa(node->flags.sign), 1);
		ft_putstr_fd("] | sp (' ') = [", 1);
		ft_putstr_fd(ft_itoa(node->flags.space), 1);
		ft_putstr_fd("] |\n", 1);
	}
}
