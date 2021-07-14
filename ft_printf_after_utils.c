/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_after_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:15:44 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/16 11:15:44 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char n)
{
	if (n == 's' || n == 'p' || n == 'c' || n == 'd'
		|| n == 'i' || n == 'x' || n == 'X' || n == 'u'
		|| n == '%')
		return (1);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointerdest;
	unsigned char	*pointersource;

	pointerdest = dest;
	pointersource = (unsigned char *)src;
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
