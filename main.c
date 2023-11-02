//#include "ft_printf.h"
#include "ft_printf_bonus.h"

int main()
{
	int i = -42;
	i = printf("%x", i);
	printf("|\nRETURN: %d\n", i);
	return (0);
}
