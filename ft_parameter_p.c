/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:04:43 by rpaulino          #+#    #+#             */
/*   Updated: 2021/06/02 16:00:36 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_times_zero(int d)
{
	char *string;
	int i;

	i = 0;
	string = (char*)malloc(sizeof(char) * d);
	while (i < d)
	{
		string[i] = '0';
		i++;
	}
	string[d] = '\0';
	return string;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointerdest;
	unsigned char	*pointersource;

	pointerdest = dest;
	pointersource = (unsigned char*)src;
	if (pointerdest == 0 && pointersource == 0)
		return (dest);
	while (n-- > 0)
		*pointerdest++ = *pointersource++;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(len * sizeof(char));
	if (dup)
	{
		ft_memcpy(dup, s, len);
	}
	return (dup);
}

void	ft_parameter_p(void *pointer, struct var *global)
{
	char *kk;
	char *times_zero;
	char *temp;
	
	if (pointer == NULL)
	{
		if (global->precision_pass)
			ft_putsomething(true, 0, "0x", global);
		else 
			ft_putsomething(true, 0, "0x0", global);
		return ;
	}
	kk = pointeraddress((unsigned long int)pointer);
	if (global->precision_size > 0 && pointer == 0)
	{
		ft_putsomething(false, 0, "0x", global);
		global->flag_zero = global->precision_size;
		global->precision_size = 0;
		ft_putsomething(true, 0, "", global);
		return ;
	}
	if (global->precision_size > (int)ft_strlen(kk) + 1)
	{
		times_zero = x_times_zero(global->precision_size - (int)ft_strlen(kk));
		temp = ft_strdup(kk);
		free(kk);
		kk = ft_strjoin(times_zero, temp);
		free(temp);
		temp = ft_strdup(kk);
		free(kk);
		kk = ft_strjoin("0x", temp);
		free(temp);
		free(times_zero);
	}
	else
	{
		temp = ft_strdup(kk);
		free(kk);
		kk = ft_strjoin("0x", temp);
		free(temp);
	}
	global->precision_size = 0;
	if(!global->precision_pass || (global->precision_pass && pointer != NULL))
	{
		ft_putsomething(true, 0, kk, global);
		free(kk);
	}
}