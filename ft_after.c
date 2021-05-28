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

char	*x_times_zero(int d)
{
	char *string;
	int i;

	i = 0;
	string = (char*)malloc(sizeof(char) * d);
	while (string[i] < d)
	{
		string[i] = '0';
		i++;
	}
	string[d] = '\0';
	return string;
}

void		type_int(int parameter, int d, int i, struct var *global)
{
	char *temp;

	temp = 0;
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
	}
	if (parameter == 'X')
	{
		temp = ft_htoa_upper(i);
		ft_putsomething(true, 0, ft_htoa_upper(i), global);
	}
	if (temp != 0)
		free(temp);
}

void		type_chr(int parameter, void *pointer, struct var *global)
{
	char *precision;
	char *kk;
	char *times_zero;
	char *temp;

	kk = NULL;
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
				free(precision);
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
		if (global->precision_size > 0 && !pointer)
		{
			ft_putsomething(false, 0, "0x", global);
			global->flag_zero = global->precision_size;
			global->precision_size = 0;
			ft_putsomething(true, 0, "", global);
			return ;
		}
		if (global->precision_size > (int)ft_strlen(kk) + 1)
		{
			times_zero = x_times_zero(global->precision_size);
			temp = tohex((unsigned long *)pointer);
			free(kk);
			kk = ft_strjoin(times_zero - (int)ft_strlen(kk), temp);
			free(temp);
			temp = kk;
			free(kk);
			kk = ft_strjoin("0x", temp);
			free(temp);
			free(times_zero);
			free(kk);
		}
		else
		{
			temp = tohex((unsigned long *)pointer);
			kk = ft_strjoin("0x", temp);
		}
		global->precision_size = 0;
		if(!global->precision_pass || (global->precision_pass && pointer != NULL))
		{
			ft_putsomething(true, 0, kk, global);
			free(kk);
		}
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
