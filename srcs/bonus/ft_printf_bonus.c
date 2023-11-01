#include "ft_printf_bonus.h"

void	ft_putstr_len(char* str, int* len)
{
	int	i;

	i = 0;
	while (str[i])
		*len += write(1, &str[i++], 1);
}

void	ft_process_c(t_node* node, char c, int* len)
{
	(void)node;
	(void)c;
	(void)len;
	printf("Processing c...\n");
}

void	ft_process_s(t_node* node, char* s, int* len)
{
	(void)node;
	(void)s;
	(void)len;
	printf("Processing s...\n");
}

void	ft_process_p(t_node* node, unsigned long long int p, int* len)
{
	(void)node;
	(void)p;
	(void)len;
	printf("Processing p...\n");
}

void	ft_process_di(t_node* node, int di, int* len)
{
	(void)node;
	(void)di;
	(void)len;
	printf("Processing di...\n");
}

void	ft_process_u(t_node* node, unsigned int u, int* len)
{
	(void)node;
	(void)u;
	(void)len;
	printf("Processing u...\n");
}

void	ft_process_xX(t_node* node, int xX, int* len)
{
	(void)node;
	(void)xX;
	(void)len;
	printf("Processing xX...\n");
}


void	ft_process(va_list ptr, t_list* head, int *len)
{
	char	conversion;
	t_node*	node;

	(void)ptr;
	(void)len;
	while (head)
	{
		node = ((t_node *)head->content);
		conversion = node->conversion;
		if (conversion == 'c')
			ft_process_c(node, va_arg(ptr, int), len);
		else if (conversion == 's')
			ft_process_s(node, va_arg(ptr, char*), len);
		else if (conversion == 'p')
			ft_process_p(node, va_arg(ptr, unsigned long long int), len);
		else if (conversion == 'd')
			ft_process_di(node, va_arg(ptr, int), len);
		else if (conversion == 'i')
			ft_process_di(node, va_arg(ptr, int), len);
		else if (conversion == 'u')
			ft_process_u(node, va_arg(ptr, unsigned int), len);
		else if (conversion == 'x')
			ft_process_xX(node, va_arg(ptr, int), len);
		else if (conversion == 'X')
			ft_process_xX(node, va_arg(ptr, int), len);
		else
			ft_putstr_len(((t_node *)head->content)->full_content, len);
		head = head->next;
	}
}

int		ft_printf(char const *s, ...)
{
	va_list	ptr;
	t_list*	head;
	int		len;

	len = 0;
	head = ft_create_nodes(s);
	ft_lstiter(head, ft_print_node);
	va_start(ptr, s);
	ft_process(ptr, head, &len);
	va_end(ptr);
	ft_lstclear(&head, ft_delete_node);
	return (len);
}
