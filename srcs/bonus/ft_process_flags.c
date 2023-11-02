#include "ft_printf_bonus.h"

void	ft_process_left_align(t_node* node, int* index, int* len)
{
	while (node->flags.left_align - (*index) > 0)
	{
		ft_putchar_len(' ', len);
		*index += 1;
	}
}

void	ft_process_precision(t_node* node, void* content, int* index, int* len)
{
	if (node->conversion == 's')
	{
		char *s = (char*)content;
		while (s[*index] && *index < node->flags.precision)
		{
			ft_putchar_len(s[*index], len);
			(*index)++;
		}
	}
}