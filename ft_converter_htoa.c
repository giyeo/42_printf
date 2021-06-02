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
	char *temp;

	char *result = (char *)malloc(sizeof(char) * 1 + 1);
	result[0] = '0';
	result[1] = '\0';
	if (n == 0)
	return "0";
	char *p = "ABCDEF";
	result = (char *)malloc(sizeof(char) * hex_len(n) + 1);
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
	temp = ft_revstr(result);
	free(result);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}

char		*ft_htoa_lower(unsigned int n)
{
	char *temp;

	char *result = (char *)malloc(sizeof(char) * 1 + 1);
	result[0] = '0';
	result[1] = '\0';
	if (n == 0)
	return result;
	free(result);
	char *p = "abcdef";
	result = (char *)malloc(sizeof(char) * hex_len(n) + 1);
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
	temp = ft_revstr(result);
	free(result);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}