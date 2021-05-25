/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:27:50 by rpaulino          #+#    #+#             */
/*   Updated: 2021/05/25 19:29:39 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_width(const char *pointer, va_list lista, struct var *global)
{
	int n;

	n = 0;
	if(ft_isdigit(pointer[0]))
	{
		global->width_size = ft_atoi(&pointer[0]);
		n = len_int(ft_atoi(&pointer[0]));
	}
	if(pointer[0] == '*')
	{
		global->width_size = va_arg(lista, int);
		if (global->width_size < 0)
		{
			global->flag_minus = global->width_size * -1;
			global->width_size = 0;
			n++;
			return n;
		}
		if (!global->width_size)
				return 0;
		n++;
	}
	return n;
}
