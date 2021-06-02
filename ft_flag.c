/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:21 by rpaulino          #+#    #+#             */
/*   Updated: 2021/06/02 05:39:33 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int until_type(const char *pointer)
{
	int i;

	i = 0;
	while(is_type(pointer[i]) == 0)
		i++;
	return i;
}

int ft_is_flag(const char *pointer, va_list lista, struct var *global)
{
	int n;
	int check;
	int current;

	current = 0;
	check = 1;
	n = 0;
	if (pointer[0] == '-' || (pointer[0] == '0' && pointer[1] == '-'))
	{
		if (pointer[1] == '0')
		{
			if (pointer[2] == '*' || ft_atoi(&pointer[2]) != 0)
			{
				global->right_zero = 1;
				n++;
				current += 2;
			}
		}
		else
		{
			if (pointer[1] == '.')
			{
				n++;
				return n;
			}
			if (pointer[0] == '0')
			{
				check++;
				n++;
			}
			n++;
			if (pointer[check] == '*')
			{
				global->flag_minus = va_arg(lista, int);
				if (global->flag_minus < 0)
					global->flag_minus *= -1;
				if (!global->flag_minus)
					return 0;
				n++;
			}
			else if (ft_isdigit(pointer[check]))
			{
				global->flag_minus = ft_atoi(&pointer[check]);
				if (ft_atoi(&pointer[check]) != 0)
					n += len_int(ft_atoi(&pointer[check]));
				n += how_many_zeros(&pointer[check]);
			}
			else
			{
				if (!is_type(pointer[check]))
				{
					global->error = true;
					return 0;
				}
			}
		}
	}
	if (current == 0)
		current = 1;
	if ((pointer[0] == '0' && pointer[1] != '-') || global->right_zero > 0)
	{
		global->zero_before = true;
		n++;
		if (pointer[0] == '0' && (pointer[1] == 'i' || pointer[1] == 'd'))
		{
			return n;
		}
		if (!ft_isdigit(pointer[current]) && pointer[current] != '*')
		{
			global->abort = true;
			return n;
		}
		if (pointer[current] == '*')
		{
			check = va_arg(lista, int);
			global->flag_zero = check;
			if (global->flag_zero < 0 && global->right_zero > 0)
			{
				global->flag_zero = 0;
				global->width_size = check * -1;
				return n + 1;
			}
			if (!global->flag_zero)
				return 0;
			n++;
		}
		if (ft_atoi(&pointer[current]) == 0 && pointer[current] != '*')
		{
			n += until_type(&pointer[current]);
			return n;
		}
		if (ft_isdigit(pointer[current]))
		{
			global->flag_zero = ft_atoi(&pointer[current]);
			n += len_int(ft_atoi(&pointer[current]));
			n += how_many_zeros(&pointer[current]);
		}
		if (global->flag_zero < 0)
		{
			global->flag_minus = global->flag_zero * -1;
			global->flag_zero = 0;
		}
	}
	return n;
}