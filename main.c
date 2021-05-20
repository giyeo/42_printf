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

	i = ft_printf("|%04.2i|\n", 42);
	i = printf("|%04.2i|\n", 42);  

	i = ft_printf("%.*s", 0, "hello2");
	i = printf("%.*s", 0, "hello1");

	i = ft_printf("%.*i\n", 6, -3);
	printf("%.*i\n", 6, -3);
	i = ft_printf("%0*i\n", 7, -54);
	printf("%0*i\n", 7, -54);

	printf("%i\n", -54);
	return (0);
}