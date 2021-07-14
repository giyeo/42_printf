/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:09:15 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/08 14:06:51 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_minus_zero(int n, const char *pointer, t_var *global)
{
	if (pointer[2] == '*' || ft_atoi(&pointer[2]) != 0)
	{
		global->right_zero = 1;
		n++;
		global->crt += 2;
	}
	return (n);
}

int	ft_minus_pzero(int n, t_var *global)
{
	global->check++;
	return (n + 1);
}

int	ft_minus_star(int n, va_list lista, t_var *global)
{
	global->flag_minus = va_arg(lista, int);
	if (global->flag_minus < 0)
		global->flag_minus *= -1;
	return (n + 1);
}

int	ft_minus_isdigit(int n, const char *pointer, t_var *global)
{
	global->flag_minus = ft_atoi(&pointer[global->check]);
	if (ft_atoi(&pointer[global->check]) != 0)
		n += len_int(ft_atoi(&pointer[global->check]));
	n += how_many_zeros(&pointer[global->check]);
	return (n);
}
