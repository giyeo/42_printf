/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:21 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/14 17:12:02 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_pminus(int n, const char *pointer, t_var *global)
{
	if (pointer[0] == '-' || (pointer[0] == '0' && pointer[1] == '-'))
	{
		if (pointer[1] == '0')
		{
			if (pointer[2] == '*' || ft_atoi(&pointer[2]) != 0)
				n = ft_minus_zero(n, pointer, global);
			if (pointer[2] == '0')
				return (n + 2);
		}
	}
	return (n);
}

int	ft_flag_minus(int n, const char *pointer, va_list lista,
	t_var *global)
{
	if (pointer[0] == '-' || (pointer[0] == '0' && pointer[1] == '-'))
	{
		if (pointer[1] == '.')
			return (n + 1);
		if (pointer[0] == '0')
			n = ft_minus_pzero(n, global);
		n++;
		if (pointer[global->check] == '*')
		{
			n = ft_minus_star(n, lista, global);
			if (!global->flag_minus)
				return (0);
		}
		else if (ft_isdigit(pointer[global->check]))
			n = ft_minus_isdigit(n, pointer, global);
		else
		{
			if (!is_type(pointer[global->check]))
			{
				global->error = true;
				return (0);
			}
		}
	}
	return (n);
}

int	ft_flag_zero(int n, const char *pointer, va_list lista,
	t_var *global)
{
	if ((pointer[0] == '0' && pointer[1] != '-') || global->right_zero > 0)
	{
		global->zero_before = true;
		n++;
		if (pointer[0] == '0' && (pointer[1] == 'i' || pointer[1] == 'd'))
			return (n);
		if (!ft_isdigit(pointer[global->crt]) && pointer[global->crt] != '*')
			return (flag_abort(n, global));
		if (pointer[global->crt] == '*')
		{
			flag_check(lista, global);
			if (global->flag_check)
				return (n + 1);
			if (!global->flag_zero)
				return (0);
			n++;
		}
		if (ft_atoi(&pointer[global->crt]) == 0 && pointer[global->crt] != '*')
			return (n + until_type(&pointer[global->crt]));
		if (ft_isdigit(pointer[global->crt]))
			n = flag_calc(n, global, pointer);
		if (global->flag_zero < 0)
			flag_minus(global);
	}
	return (n);
}

int	ft_is_flag(const char *pointer, va_list lista, t_var *global)
{
	int	n;

	n = 0;
	n = ft_flag_pminus(n, pointer, global);
	if (!n)
		n = ft_flag_minus(n, pointer, lista, global);
	if (global->crt == 0)
		global->crt = 1;
	n = ft_flag_zero(n, pointer, lista, global);
	return (n);
}
