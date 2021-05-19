/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:43:37 by rpaulino          #+#    #+#             */
/*   Updated: 2021/03/27 12:43:37 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_htoa_upper(unsigned int n)
{
	if (n == 0)
	return "0";
	char *p = "ABCDEF";
	char *result = (char *)malloc(sizeof(char) * hex_len(n) + 1);
	int i;

	i = 0;
	while (n > 0)
	{
		if ((n % 16) < 10)
			result[i] = n % 16 + '0';
		else
			result[i] = p[((n % 16) % 10)];
		n /= 16;
		i++;
	}
	result[i] = '\0';
	return (ft_revstr(result));
}

char		*ft_htoa_lower(unsigned int n)
{
	if (n == 0)
	return "0";
	char *p = "abcdef";
	char *result = (char *)malloc(sizeof(char) * hex_len(n) + 1);
	int i;

	i = 0;
	while (n > 0)
	{
		if ((n % 16) < 10)
			result[i] = n % 16 + '0';
		else
			result[i] = p[((n % 16) % 10)];
		n /= 16;
		i++;
	}
	result[i] = '\0';
	return (ft_revstr(result));
}