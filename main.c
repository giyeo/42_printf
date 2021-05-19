#include "ft_printf.h"
int		main(void)
{
	int i;
	i = ft_printf("oi%10s", "{lala}"); printf("	%d\n", i);
	i = printf("oi%10s", "{lala}"); printf("	%d\n", i);
	return (0);
}