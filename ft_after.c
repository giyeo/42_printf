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

int ft_next_nbr(const char *pointer)
{
    return ft_atoi(pointer);
}

int ft_is_flag(const char *pointer, va_list lista, struct var *global)
{
    int n;

	n = 0;
    if (pointer[0] == '-')
    {
		n++;
        if (pointer[1] == '*')
        {
            global->flag_minus = va_arg(lista, int);
            n++;
        }
        if (ft_isdigit(pointer[1]))
        {
            global->flag_minus = ft_next_nbr(&pointer[1]);
            n += len_int(ft_next_nbr(&pointer[1]));
        }
    }
    if (pointer[0] == '0')
    {   
		n++;
        if (pointer[1] == '*')
        {
            global->flag_zero = va_arg(lista, int);
            n++;
        }
        if (ft_isdigit(pointer[1]))
        {
            global->flag_zero = ft_next_nbr(&pointer[1]);
            n += len_int(ft_next_nbr(&pointer[1]));
        }
    }
    return n;
}

int	ft_is_width(const char *pointer, va_list lista, struct var *global)
{
	int n;

	n = 0;
	if(ft_isdigit(pointer[0]))
	{
		global->width_size = ft_next_nbr(&pointer[0]);
		n = len_int(ft_next_nbr(&pointer[0]));
	}
	if(pointer[0] == '*')
	{
		global->width_size = va_arg(lista, int);
		n++;
	}
	return n;
}

int	ft_is_precision(const char *pointer, va_list lista, struct var *global)
{
	int	n;

	n = 0;
	if(pointer[0] == '.')
	{
		n++;
		if (ft_isdigit(pointer[1]))
		{
			global->precision_size = ft_next_nbr(&pointer[0]);
			n += len_int(ft_next_nbr(&pointer[0]));
		}
		if (pointer[1] == '*')
		{
			global->precision_size = va_arg(lista, int);
			n++;
		}
	}
	return n;
}


void		type_int(int parameter, int d, unsigned int i, struct var *global)
{
	if (parameter == 'd' && global->precision_size > 0)
	{
		if (len_int(d) < global->precision_size)
			global->flag_zero = global->precision_size - len_int(d) + ft_strlen(ft_itoa(d));
	}
	if (parameter == 'c')
		ft_putsomething(true, d, 0, global);
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

	precision = 0;
	if (parameter == 's' && global->precision_size > 0)
	{
		if (global->precision_size < ft_strlen((char *)pointer))
			precision = ft_substr((char *)pointer, 0, global->precision_size);
	}
	if (parameter == 's')
	{ 
		if (pointer == NULL)
			ft_putsomething(false, 0, "(null)", global);
		else if (precision != 0)
			ft_putsomething(true, 0, precision, global);
		else
			ft_putsomething(true, 0, (char *)pointer, global);
	}
	if (parameter == 'p')
	{
		ft_putsomething(false, 0, "0x", global);
		ft_putsomething(true, 0, tohex((unsigned long *)pointer), global);
	}
}

void	ft_after(const char *pointer, va_list lista, struct var *global)
{
	int i;

	i = 0;
    i += ft_is_flag(&pointer[i], lista, global);
	i += ft_is_width(&pointer[i], lista, global);
	i += ft_is_precision(&pointer[i], lista, global);
	if (pointer[i] == '%')
		ft_putsomething(false, '%', 0, global);
	if (pointer[i] == 's' || pointer[i] == 'p')
		type_chr(pointer[i], va_arg(lista, void*), global);
	if (pointer[i] == 'd' || pointer[i] == 'i' || pointer[i] == 'c')
		type_int(pointer[i], va_arg(lista, int), 0, global);
	if (pointer[i] == 'u' || pointer[i] == 'x' || pointer[i] == 'X')
		type_int(pointer[i], 0, va_arg(lista, unsigned int), global);
}
