#include <stdio.h>

int	ft_isdigit(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
}

int ft_next_nbr(const char *pointer)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (ft_isdigit(pointer[i]) == 1)
    {
		result *= 10; 
		result += pointer[i];
		i++;
    }
    return result;
}

int main(void)
{
	int i = printf("%3.1s", NULL); printf(" %d\n", i); 
	i = printf("%3.2s", NULL); printf(" %d\n", i);
	i = printf("%3.3s", NULL); printf(" %d\n", i);
	i = printf("%3.4s", NULL); printf(" %d\n", i);
	i = printf("%3.5s", NULL); printf(" %d\n", i);
	i = printf("%3.6s", NULL); printf(" %d\n", i);
	i = printf("%3.7s", NULL); printf(" %d\n", i);
	return (0);
}