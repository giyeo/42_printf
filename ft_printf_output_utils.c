/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:10:40 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/16 11:10:40 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_manager(bool type, char c, t_var *global)
{
	while (global->width_size > 0 && type)
	{
		ft_putchar_fd(' ', 1);
		global->width_size--;
		global->final_size++;
	}
	ft_putchar_fd(c, 1);
	while (global->flag_minus > 0 && type)
	{
		ft_putchar_fd(' ', 1);
		global->flag_minus--;
		global->final_size++;
	}
	if (type)
		global->flag_minus -= 1;
	global->final_size++;
}

void	ft_putstr_manager(bool type, char *s, t_var *global)
{
	while (global->width_size > 0 && type)
	{
		ft_putchar_fd(' ', 1);
		global->width_size--;
		global->final_size++;
	}
	if (global->print_a_minus)
		ft_putsomething(false, '-', 0, global);
	while (global->flag_zero > 0 && type)
	{
		ft_putchar_fd('0', 1);
		global->flag_zero--;
		global->final_size++;
	}
	ft_putstr_fd(s, 1);
	while (global->flag_minus > 0 && type)
	{
		ft_putchar_fd(' ', 1);
		global->flag_minus--;
		global->final_size++;
	}
}

void	ft_s_typetrue(char *s, t_var *global)
{
	global->flag_minus = global->flag_minus - ft_strlen(s);
	global->flag_zero = global->flag_zero - ft_strlen(s);
	global->width_size = global->width_size - ft_strlen(s);
	if (global->print_a_minus)
	{
		global->flag_minus--;
		global->width_size--;
		global->flag_zero--;
	}
	if (global->prec_size > 0)
	{
		global->width_size -= global->flag_zero;
		global->flag_minus -= global->flag_zero;
	}
}

void	ft_rzero_bzero(t_var *global)
{
	if (global->width_size > 0)
	{
		global->flag_minus = global->width_size;
		global->width_size = 0;
	}
	else if (global->flag_zero > 0)
	{
		global->flag_minus = global->flag_zero;
		global->flag_zero = 0;
	}
}

void	ft_putsomething(bool type, char c, char *s, t_var *global)
{
	if (!s)
		ft_putchar_manager(type, c, global);
	else
	{
		if (type)
			ft_s_typetrue(s, global);
		if (global->right_zero > 0)
			ft_rzero_bzero(global);
		ft_putstr_manager(type, s, global);
		global->final_size += ft_strlen(s);
	}
}
