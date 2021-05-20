#include "ft_printf.h"
int		main(void)
{
	int i;
	i = ft_printf("oi%05d", 4); printf(" %d\n", i);
	i = printf("oi%05d", 4); printf(" %d\n", i);
	i = ft_printf("%.*d", 7, 51234); printf(" %d\n", i);
	i = printf("%.*d", 7, 51234); printf(" %d\n", i);
	i = ft_printf("%.*s", 3, "bonodia"); printf(" %d\n", i);
	i = printf("%.*s", 3, "bonodia"); printf(" %d\n", i);

	return (0);
}