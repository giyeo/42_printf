/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_after_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:15:44 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/16 11:15:44 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			next_char(const char *pointer)
{
	while (*pointer != '\0')
	{
		if (*pointer == 'c')
			return (2);
		if (*pointer == 'd' || *pointer == 'i')
			return (0);
		if (*pointer == 's')
			return (1);
		pointer++;
	}
	return (-1);
}

int			len_d(va_list lista, int s)
{
	va_list cpy_lista;
	int print;
	va_copy(cpy_lista, lista);
	if (!s)
		print = len_int(va_arg(cpy_lista, int));
	else
		print = len_int(va_arg(cpy_lista, int) * -1);
	va_end(cpy_lista);
	return print;
}

int		counting_stars(char const *pointer)
{
	int i;
	int stars;

	stars = 0;
	i = 1;
	while (is_type(pointer[i]) == 0)
	{
		if(pointer[i] == '*')
			stars++;
		i += 1;
	}
	return stars;
}
int		len_check(char const *pointer, va_list lista)
{
	va_list cpy_lista;
	int print;
	int stars;
	va_copy(cpy_lista, lista);

	stars = counting_stars(pointer);
	while (stars > 0)
	{
		stars--;
		va_arg(cpy_lista, int);
	}
	if (next_char(pointer) == 1)
		print = (ft_strlen(va_arg(cpy_lista, char*)));
	else if (next_char(pointer) == 2)
		print = (ft_strlen(chtostr(va_arg(cpy_lista, int))));
	else
		print = ft_strlen(ft_itoa(va_arg(cpy_lista, int)));
	if (print == 0)
		return 1;
	va_end(cpy_lista);
	return print;
}

int 	is_type(char n)
{
	if (n == 's' || n == 'p' || n == 'c' || n == 'd' ||
		n == 'i' || n == 'x' || n == 'X' || n == 'u' ||
		n == '%')
		return 1;
	return 0;
}