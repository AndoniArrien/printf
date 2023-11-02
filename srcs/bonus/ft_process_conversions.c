#include "ft_printf_bonus.h"

// POSIBLE_FLAGS: "-0.#+ "

// FLAGS: "-"
void	ft_process_c(t_node* node, char c, int* len)
{
	int	i;

	i = 0;
	i += 1;
	ft_putchar_len(c, len);

	ft_process_left_align(node, &i, len);
}

// FLAGS: "-."
void	ft_process_s(t_node* node, char* s, int* len)
{
	int	i;

	i = 0;
	ft_process_precision(node, s, &i, len);
	if (node->flags.precision == 0)
		i += ft_strlen(s);

	ft_process_left_align(node, &i, len);
}

// FLAGS: "-"
void	ft_process_p(t_node* node, unsigned long long int p, int* len)
{
	(void)node;
	(void)p;
	(void)len;
	printf("Processing p...\n");
}

// FLAGS: "-0.+ "
void	ft_process_di(t_node* node, int di, int* len)
{
	(void)node;
	(void)di;
	(void)len;
	printf("Processing di...\n");
}

// FLAGS: "-0."
void	ft_process_u(t_node* node, unsigned int u, int* len)
{
	(void)node;
	(void)u;
	(void)len;
	printf("Processing u...\n");
}

// FLAGS: "-0." ****
void	ft_process_xX(t_node* node, int xX, int* len)
{
	(void)node;
	(void)xX;
	(void)len;
	printf("Processing xX...\n");
}