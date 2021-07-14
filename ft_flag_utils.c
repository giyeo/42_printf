/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:18:09 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/14 17:12:02 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	until_type(const char *pointer)
{
	int	i;

	i = 0;
	while (is_type(pointer[i]) == 0)
		i++;
	return (i);
}

int	flag_abort(int n, t_var *global)
{
	global->abort = true;
	return (n);
}

void	flag_check(va_list lista, t_var *global)
{
	global->check = va_arg(lista, int);
	global->flag_zero = global->check;
	if (global->flag_zero < 0 && global->right_zero > 0)
	{
		global->flag_check = true;
		global->flag_zero = 0;
		global->width_size = global->check * -1;
	}
}

int	flag_calc(int n, t_var *global, const char *pointer)
{
	global->flag_zero = ft_atoi(&pointer[global->crt]);
	n += len_int(ft_atoi(&pointer[global->crt]));
	n += how_many_zeros(&pointer[global->crt]);
	return (n);
}

void	flag_minus(t_var *global)
{
	global->flag_minus = global->flag_zero * -1;
	global->flag_zero = 0;
}
