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

void		type_int(int parameter, int d, unsigned int i, struct var *global)
{
	char *temp;

	global->precision_x = global->precision_size;
	temp = 0;
	if ((d == 0 && i == 0) && global->noPrecVal)
	{
		ft_putsomething(true, 0, "", global);
		return;
	}
	if (parameter == 'u')
		i = ft_prec_error_hand_u(i, global);
	if (((parameter == 'd' || parameter == 'i') || d) && parameter != 'c')
		d = ft_prec_error_hand(parameter, d, global);
	if (parameter == 'x' || parameter == 'X')
		ft_prec_error_hand_x(i, global);
	if (parameter == 'c')
	{
		ft_prec_error_hand_c(global);
		ft_putsomething(true, d, 0, global);
	}
	if (parameter == 'd')
	{
		temp = ft_itoa(d);
		ft_putsomething(true, 0, temp, global);
	}
	if (parameter == 'i')
	{
		temp = ft_itoa(d);
		ft_putsomething(true, 0, temp, global);
	}
	if (parameter == 'u')
	{
		temp = ft_utoa(i);
		ft_putsomething(true, 0, temp, global);
	}
	if (parameter == 'x')
	{
		temp = ft_htoa_lower(i);
		ft_putsomething(true, 0, temp, global);
		if (temp[0] == '0' && ft_strlen(temp) == 1)
			return;
	}
	if (parameter == 'X')
	{
		temp = ft_htoa_upper(i);
		ft_putsomething(true, 0, temp, global);
		if (temp[0] == '0' && ft_strlen(temp) == 1)
			return;
	}
	if (temp != 0)
		free(temp);
}

void	type_chr(int parameter, void *pointer, struct var *global)
{
	if (parameter == 's')
		ft_parameter_s((char *)pointer, global);
	if (parameter == 'p')
		ft_parameter_p(pointer, global);
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
		if(is_type(pointer[i]))
			va_arg(lista, void*);
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
