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

	ft_printf("%*sa\n", -32, "abc");
	printf("%*sa\n", -32, "abc");
	ft_printf("%-*sa\n", -32, "abc");
	printf("%-*sa\n", -32, "abc");

	ft_printf("%-*.*sa\n", -7, -3, "yolo");
	printf("%-*.*sa\n", -7, -3, "yolo");
	ft_printf("%*ia\n", -14, 94827);
	printf("%*ia\n", -14, 94827);
	ft_printf("%0*ia\n", -7, -54);
	printf("%0*ia\n", -7, -54);

	ft_printf("%.6d\n", -3);
	printf("%.6d\n", -3);

	ft_printf("%.s\n", "hello");
	printf("%.s\n", "hello");
	ft_printf("%.0s\n", "hello");
	printf("%.0s\n", "hello");

	i = ft_printf("%32s", NULL); printf(" %d\n", i);
	i = ft_printf("%2s", NULL); printf(" %d\n", i);
	i = ft_printf("%-32s", NULL); printf(" %d\n", i);
	i = ft_printf("%-16s", NULL); printf(" %d\n", i);

	i = printf("%32s", NULL); printf(" %d\n", i);
	i = printf("%2s", NULL); printf(" %d\n", i);
	i = printf("%-32s", NULL); printf(" %d\n", i);
	i = printf("%-16s", NULL); printf(" %d\n", i);

	static char *s_hidden = "hi low\0don't print me lol\0";
	i = ft_printf("%.03s", s_hidden); printf(" %d\n", i);
	i = ft_printf("%.09s", s_hidden); printf(" %d\n", i);
	i = ft_printf("%.03s", NULL); printf(" %d\n", i);
	i = ft_printf("%.09s", NULL); printf(" %d\n", i);

	i = printf("%.03s", s_hidden); printf(" %d\n", i);
	i = printf("%.09s", s_hidden); printf(" %d\n", i);
	i = printf("%.03s", NULL); printf(" %d\n", i);
	i = printf("%.09s", NULL); printf(" %d\n", i);

	i = ft_printf("%3.s", s_hidden); printf(" %d\n", i);
	i = ft_printf("%10.s", s_hidden);printf(" %d\n", i);
	i = ft_printf("%3.s", NULL);printf(" %d\n", i);
	i = ft_printf("%10.s", NULL);printf(" %d\n", i);
	i = ft_printf("%1.s", "\0");printf(" %d\n", i);
	i = ft_printf("%2.s", "\0");printf(" %d\n", i);
	i = ft_printf("%9.s", "\0");printf(" %d\n", i);
	printf("----------------\n");
	i = printf("%3.s", s_hidden); printf(" %d\n", i);
	i = printf("%10.s", s_hidden);printf(" %d\n", i);
	i = printf("%3.s", NULL);printf(" %d\n", i);
	i = printf("%10.s", NULL);printf(" %d\n", i);
	i = printf("%1.s", "\0");printf(" %d\n", i);
	i = printf("%2.s", "\0");printf(" %d\n", i);
	i = printf("%9.s", "\0");printf(" %d\n", i);
	return (0);
}