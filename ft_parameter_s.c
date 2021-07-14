/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:09:25 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/08 14:06:51 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parameter_s_output(char *pointer, t_var *global, char *precision)
{
	if (pointer == NULL)
		ft_putsomething(true, 0, "(null)", global);
	else if (precision != 0)
	{
		ft_putsomething(true, 0, precision, global);
		free(precision);
	}
	else
		ft_putsomething(true, 0, pointer, global);
}

void	pointer_s_null(t_var *global)
{
	char	*precision;

	precision = 0;
	if (global->prec_size < (int)ft_strlen("(null)"))
	{
		global->flag_minus--;
		global->width_size--;
		precision = ft_substr("(null)", 0, global->prec_size);
		ft_putsomething(true, 0, precision, global);
		free(precision);
	}
	else
	{
		global->prec_size = 0;
		ft_putsomething(true, 0, "(null)", global);
	}
}

void	ft_parameter_s(char *pointer, t_var *global)
{
	char	*precision;

	precision = 0;
	if (global->prec_size > 0)
	{
		if (pointer == NULL)
		{
			pointer_s_null(global);
			return ;
		}
		if (global->prec_size < (int)ft_strlen(pointer))
		{
			precision = ft_substr(pointer, 0, global->prec_size);
			global->prec_size = 0;
		}
	}
	global->prec_size = 0;
	parameter_s_output(pointer, global, precision);
}
