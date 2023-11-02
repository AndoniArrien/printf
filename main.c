//#include "ft_printf.h"
#include "ft_printf_bonus.h"

int main()
{
	int	original_return;
	int	copy_return;

	printf("\nORIGINAL:\n");
	original_return = printf("%-16.1s %-12c", "Hola mundo", 'X');
	printf("|\nCOPY:\n");
	copy_return = ft_printf("%-16.1s %-12c", "Hola mundo", 'X');
	printf("|\nRETURNS: ORIGINAL = [%d] COPY = [%d]\n", original_return, copy_return);
	return (0);
}
