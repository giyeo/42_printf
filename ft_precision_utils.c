/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:05:11 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/08 14:06:51 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_n_bt_prec(t_var *global, int is_unsigned)
{
	if (global->zero_before && global->prec_size > 0)
	{
		global->width_size += global->flag_zero;
		global->flag_zero = 0;
	}
	if (is_unsigned != 0)
		global->precision_x = global->prec_size;
	global->prec_size = 0;
}

int	how_many_zeros(const char *pointer)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (pointer[i] == '0')
	{
		i++;
		n++;
	}
	return (n);
}

int	case_d_mzero(int d, t_var *global)
{
	d *= -1;
	global->print_a_minus = true;
	if (global->flag_zero == 0)
		global->flag_zero++;
	return (d);
}

int	len_prec_error_hand(int d, t_var *global)
{
	char	*temp;
	int		n;

	n = 0;
	global->o_zero = global->flag_zero;
	temp = ft_itoa(d);
	n = ft_strlen(temp);
	free(temp);
	return (n);
}
