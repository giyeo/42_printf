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

	i = ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	i = printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	i = ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	i = printf("%%04.5i 42 == |%04.5i|\n", 42);
	
	i = ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	i = printf("%%04.3i 42 == |%04.3i|\n", 42);
	i = ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	i = printf("%%04.2i 42 == |%04.2i|\n", 42);

	return (0);
}