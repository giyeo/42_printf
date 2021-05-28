/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:04:43 by rpaulino          #+#    #+#             */
/*   Updated: 2021/05/28 15:08:39 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parameter_p(void *pointer, struct var *global)
{
	char *kk;
	char *times_zero;
	char *temp;

	kk = NULL;
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
		kk = ft_strjoin(times_zero - (int)ft_strlen(kk), temp);
		temp = kk;
		kk = ft_strjoin("0x", temp);
	}
	else
	{
		temp = tohex((unsigned long *)pointer);
		kk = ft_strjoin("0x", temp);
	}
	global->precision_size = 0;
	if(!global->precision_pass || (global->precision_pass && pointer != NULL))
		ft_putsomething(true, 0, kk, global);
	else
		ft_putsomething(true, 0, "0x", global);
}