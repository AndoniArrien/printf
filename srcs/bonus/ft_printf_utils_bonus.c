#include "ft_printf_bonus.h"

void	ft_print_nodes(t_node* head)
{
	int	i;

	i = 0;
	while(head)
	{
		printf("Node %02dº: %s\n", i++, head->full_content);
		head = head->next;
	}
}