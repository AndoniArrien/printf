#include "ft_printf_bonus.h"

// POSIBLE_FLAGS: "-0.#+ "

// FLAGS: "-"
void	ft_process_c(t_node* node, char c, int* len)
{
	(void)node;
	(void)c;
	(void)len;
	printf("Processing c...\n");
}

// FLAGS: "-."
void	ft_process_s(t_node* node, char* s, int* len)
{
	(void)node;
	(void)s;
	(void)len;
	printf("Processing s...\n");
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