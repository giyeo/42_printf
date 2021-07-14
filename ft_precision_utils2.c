/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 10:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/14 17:15:01 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prec_abort_one(t_var *global)
{
	global->abort = true;
	return (2);
}

int	prec_noprec(int n, t_var *global)
{
	global->noPrecVal = true;
	return (n + 1);
}

int	prec_set(int n, t_var *global)
{
	global->width_size = global->flag_zero;
	global->flag_zero = 0;
	global->noPrecVal = true;
	return (n + 1);
}

int	prec_abort_two(int n, t_var *global)
{
	global->abort = true;
	return (n);
}

int	prec_calc(int n, t_var *global, int check, const char *pointer)
{
	global->prec_size = check;
	n += len_int(check) + how_many_zeros(&pointer[1]);
	return (n);
}
