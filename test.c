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
	const char *format = "2s";
	printf("%d", ft_next_nbr(format));
	printf("%d", 's');
	return (0);
}