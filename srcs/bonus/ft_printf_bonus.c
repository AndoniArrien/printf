#include "ft_printf_bonus.h"

int	ft_printf(char const *s, ...)
{
	va_list	ptr;
	t_list*	head;
	int		len;

	len = 0;
	head = ft_create_nodes(s);
	va_start(ptr, s);
	va_end(ptr);
	ft_lstclear(&head, ft_delete_node);
	return (len);
}
