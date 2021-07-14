/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:06 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/14 17:15:01 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_precision(const char *pointer, va_list lista,
	t_var *global)
{
	int	n;
	int	check;

	n = 0;
	global->precision_pass = true;
	if (pointer[1] == '0' && pointer[2] == 's')
		return (prec_abort_one(global));
	n++;
	check = ft_atoi(&pointer[1]);
	if (global->width_size > 0 && (pointer[1] == '0' && check == 0))
		return (prec_noprec(n, global));
	if (check == 0 && pointer[1] == '0')
		return (prec_set(n, global));
	if (is_type(pointer[1]) && !check && pointer[1] != 'p')
		return (prec_abort_two(n, global));
	if (check)
		n = prec_calc(n, global, check, pointer);
	if (pointer[1] == '*')
	{
		global->prec_size = va_arg(lista, int);
		if (!global->prec_size)
			return (0);
		n++;
	}
	return (n);
}

int	ft_prec_error_hand(int d, t_var *global)
{
	int	n;

	if (d < 0 && d != -2147483648)
		d = case_d_mzero(d, global);
	n = len_prec_error_hand(d, global);
	if (n < global->prec_size)
		global->flag_zero += (global->prec_size - n) + n;
	else
		ft_prec_n_bt_prec(global, 0);
	if (global->zero_before && global->prec_size > 0)
	{
		global->flag_zero -= global->prec_size
			+ (global->o_zero - global->prec_size);
		global->width_size += n + (global->o_zero - global->prec_size);
		global->prec_size = 0;
		if (global->print_a_minus)
			global->flag_zero++;
	}
	return (d);
}

void	ft_prec_error_hand_c(t_var *global)
{
	global->width_size -= 1;
	global->flag_minus -= 1;
}

int	ft_prec_error_hand_u(unsigned int u, t_var *global)
{
	int	n;
	int	o_zero;

	o_zero = global->flag_zero;
	n = len_int(u);
	if (n < global->prec_size)
		global->flag_zero += (global->prec_size - n) + n;
	else
		ft_prec_n_bt_prec(global, 1);
	if (global->zero_before && global->prec_size > 0)
	{
		global->flag_zero -= global->prec_size
			+ (o_zero - global->prec_size);
		global->width_size += n + (o_zero - global->prec_size);
		global->precision_x = global->prec_size;
		global->prec_size = 0;
	}
	return (u);
}

int	ft_prec_error_hand_x(int parameter, unsigned int u, t_var *global)
{
	int		n;
	char	*temp;
	int		o_zero;

	o_zero = global->flag_zero;
	if (parameter == 'x')
		temp = ft_htoa_lower(u);
	else
		temp = ft_htoa_upper(u);
	n = ft_strlen(temp);
	free(temp);
	if (n < global->prec_size)
		global->flag_zero += (global->prec_size - n) + n;
	else
		ft_prec_n_bt_prec(global, 1);
	if (global->zero_before && global->prec_size > 0)
	{
		global->flag_zero -= global->prec_size
			+ (o_zero - global->prec_size);
		global->width_size += n + (o_zero - global->prec_size);
		global->precision_x = global->prec_size;
		global->prec_size = 0;
	}
	return (u);
}
