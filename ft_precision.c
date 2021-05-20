/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:06 by rpaulino          #+#    #+#             */
/*   Updated: 2021/05/20 18:25:30 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_precision(const char *pointer, va_list lista, struct var *global)
{
	int	n;

	n = 0;
	if(pointer[0] == '.')
	{
		n++;
		if (is_type(pointer[1]) || pointer[1] == '0')
		{
			global->abort = true;
			return 0;
		}
		if (ft_isdigit(pointer[1]))
		{
			global->precision_size = ft_atoi(&pointer[1]);
			n += len_int(ft_atoi(&pointer[1]));
		}
		if (pointer[1] == '*')
		{
			global->precision_size = va_arg(lista, int);
			if (!global->precision_size)
				return 0;
			n++;
		}
	} 
	return n;
}

int	ft_prec_error_hand(int parameter, int d, unsigned int i, struct var *global)
{
	if (parameter == 'd' && global->precision_size > 0)
	{
		global->width_size += global->flag_zero;
		if (len_int(d) < global->precision_size)
			global->flag_zero = global->precision_size - len_int(d) + ft_strlen(ft_itoa(d));
		global->width_size -= global->precision_size - len_int(d) - 1;
	}
	if (parameter == 'i' && global->precision_size > 0)
	{
		global->width_size += global->flag_zero;
		if (len_int(i) < global->precision_size)
			global->flag_zero = global->precision_size - len_int(i) + ft_strlen(ft_itoa(i));
		global->width_size -= global->precision_size - len_int(i) - 1;
	}
	if ((d < 0 || i < 0) && global->precision_size > 0)
		global->prec_print_minus = true;
	if ((d < 0 || i < 0) && global->flag_zero > 0)
	{
		i *= -1;
		d *= -1;
		global->print_a_minus = true;
	}
	if (d)
		return d;
	else
		return i;
}