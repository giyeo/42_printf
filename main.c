#include "ft_printf.h"
int		main(void)
{
	int i;
	i = ft_printf("oi%05d", 4); printf(" %d\n", i);
	i = printf("oi%05d", 4); printf(" %d\n", i);
	return (0);
}