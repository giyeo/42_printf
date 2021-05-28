/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:25:31 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/06 13:25:31 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pointeraddress(unsigned long int n)
{
	char *temp;

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
	temp = ft_revstr(result);
	free(result);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}
