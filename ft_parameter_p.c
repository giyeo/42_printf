/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:04:43 by rpaulino          #+#    #+#             */
/*   Updated: 2021/07/08 14:06:51 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_times_zero(int d)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc(sizeof(char) * d);
	while (i < d)
	{
		string[i] = '0';
		i++;
	}
	string[d] = '\0';
	return (string);
}

char	*prec_bsize(char *p_address, t_var *global)
{
	char	*times_zero;
	char	*temp;

	if (global->prec_size > (int)ft_strlen(p_address) + 1)
	{
		times_zero = x_times_zero(global->prec_size
				- (int)ft_strlen(p_address));
		temp = ft_strdup(p_address);
		free(p_address);
		p_address = ft_strjoin(times_zero, temp);
		free(temp);
		temp = ft_strdup(p_address);
		free(p_address);
		p_address = ft_strjoin("0x", temp);
		free(temp);
		free(times_zero);
	}
	else
	{
		temp = ft_strdup(p_address);
		free(p_address);
		p_address = ft_strjoin("0x", temp);
		free(temp);
	}
	return (p_address);
}

void	pointer_p_null(t_var *global)
{
	if (global->precision_pass)
	{
		if (global->prec_size > 0)
		{
			global->flag_zero = global->prec_size;
			global->prec_size = 0;
			ft_putsomething(false, 0, "0x", global);
			ft_putsomething(true, 0, "", global);
		}
		else
			ft_putsomething(true, 0, "0x", global);
	}
	else
		ft_putsomething(true, 0, "0x0", global);
}

void	ft_parameter_p(void *pointer, t_var *global)
{
	char	*p_address;

	if (pointer == NULL)
	{
		pointer_p_null(global);
		return ;
	}
	p_address = pointeraddress((unsigned long int)pointer);
	if (global->prec_size > 0 && pointer == 0)
	{
		ft_putsomething(false, 0, "0x", global);
		global->flag_zero = global->prec_size;
		global->prec_size = 0;
		ft_putsomething(true, 0, "", global);
		return ;
	}
	p_address = prec_bsize(p_address, global);
	global->prec_size = 0;
	if (!global->precision_pass || (global->precision_pass && pointer != NULL))
	{
		ft_putsomething(true, 0, p_address, global);
		free(p_address);
	}
}
