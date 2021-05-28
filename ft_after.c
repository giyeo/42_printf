/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:20:15 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/14 16:08:17 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_int(int parameter, int d, int i, struct var *global)
{
	if ((d == 0 && i == 0) && global->noPrecVal)
	{
		ft_putsomething(true, 0, "", global);
		return;
	}
	if (i || parameter == 'u' || parameter == 'x' || parameter == 'X')
		i = ft_prec_error_hand_u(i, global);
	if (((parameter == 'd' || parameter == 'i') || d) && parameter != 'c')
		d = ft_prec_error_hand(parameter, d, global);
	if (parameter == 'c')
	{
		ft_prec_error_hand_c(global);
		ft_putsomething(true, d, 0, global);
	}
	if (parameter == 'd')
		ft_putsomething(true, 0, ft_itoa(d), global);
	if (parameter == 'i')
		ft_putsomething(true, 0, ft_itoa(d), global);
	if (parameter == 'u')
		ft_putsomething(true, 0, ft_utoa(i), global);
	if (parameter == 'x')
		ft_putsomething(true, 0, ft_htoa_lower(i), global);
	if (parameter == 'X')
		ft_putsomething(true, 0, ft_htoa_upper(i), global);
}

void		type_chr(int parameter, void *pointer, struct var *global)
{
	char *precision;

	int i;

	i = global->precision_size;
	precision = 0;
	if (parameter == 's' && global->precision_size > 0)
	{
		if (pointer == NULL)
		{
			if (global->precision_size < (int)ft_strlen("(null)"))
			{
				global->flag_minus--;
				global->width_size--;
				precision = ft_substr("(null)", 0, global->precision_size);
				ft_putsomething(true, 0, precision, global);
			}
			else
			{
				global->precision_size = 0;
				ft_putsomething(true, 0, "(null)", global);
			}
			return ;
		}
		if (global->precision_size < (int)ft_strlen((char *)pointer))
		{
			precision = ft_substr((char *)pointer, 0, global->precision_size);
			global->precision_size = 0;
		}
	}
	if (parameter == 's')
	{ 
		global->precision_size = 0;
		if (pointer == NULL)
			ft_putsomething(true, 0, "(null)", global);
		else if (precision != 0)
			ft_putsomething(true, 0, precision, global);
		else
			ft_putsomething(true, 0, (char *)pointer, global);
	}
	if (parameter == 'p')
	{
		global->precision_size = 0;
		char *kk = ft_strjoin("0x", tohex((unsigned long *)pointer));
		if(!global->precision_pass || (global->precision_pass && pointer != NULL))
			ft_putsomething(true, 0, kk, global);
		else
			ft_putsomething(true, 0, "0x", global);
	}
}

void	ft_after(const char *pointer, va_list lista, struct var *global)
{
	int i;

	i = 0;
    i += ft_is_flag(&pointer[i], lista, global);
	i += ft_is_width(&pointer[i], lista, global);
	i += ft_is_precision(&pointer[i], lista, global);
	if (global->abort)
	{
		ft_putsomething(true, 0, "", global);
		return ;
	}
	if (pointer[i] == '%')
		ft_putsomething(true, 0, "%", global);
	if (pointer[i] == 's' || pointer[i] == 'p')
	{
		global->zero_string = true;
		type_chr(pointer[i], va_arg(lista, void*), global);
	}
	if (pointer[i] == 'd' || pointer[i] == 'i' || pointer[i] == 'c')
		type_int(pointer[i], va_arg(lista, int), 0, global);
	if (pointer[i] == 'u' || pointer[i] == 'x' || pointer[i] == 'X')
		type_int(pointer[i], 0, va_arg(lista, unsigned int), global);
}
