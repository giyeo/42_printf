/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:09:25 by rpaulino          #+#    #+#             */
/*   Updated: 2021/05/28 15:12:16 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parameter_s(void *pointer, struct var *global)
{
	char *precision;

	precision = 0;
	if (global->precision_size > 0)
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
		global->precision_size = 0;
		if (pointer == NULL)
			ft_putsomething(true, 0, "(null)", global);
		else if (precision != 0)
			ft_putsomething(true, 0, precision, global);
		else
			ft_putsomething(true, 0, (char *)pointer, global);
}
