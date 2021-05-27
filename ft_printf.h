/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:25:29 by rpaulino          #+#    #+#             */
/*   Updated: 2021/03/27 11:25:29 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>

struct var
{
	bool	noPrecVal;
	bool	zero_before;
	bool	zero_string;
	bool	error;
	bool	abort;
	bool	prec_print_minus;
	bool	print_a_minus;
	int		flag_minus;
	int		flag_zero;
	int		width_size;
	int		precision_size;
	int		final_size;
};

int				ft_is_precision(const char *pointer, va_list lista, struct var *global);
int				ft_prec_error_hand(int parameter, int d, struct var *global);
void			ft_prec_error_hand_c(int d, struct var *global);
int				ft_prec_error_hand_u(unsigned int u, struct var *global);
int				ft_is_flag(const char *pointer, va_list lista, struct var *global);
int				ft_is_width(const char *pointer, va_list lista, struct var *global);

int				how_many_zeros(const char *pointer);
int				ft_printf(const char *format, ...);
char			*ft_itoa(int n);
char			*ft_htoa_upper(unsigned int n);
char			*ft_htoa_lower(unsigned int n);
char			*tohex(unsigned long *pointer);
char			*chtostr(int c);
int				next_char(const char *pointer);
int				len_d(va_list lista, int s);
int				len_check(char const *pointer, va_list lista);
const char		*sumpointer(const char *pointer, int dif);
int				ft_isdigit(int argument);
int 			is_type(char n);
int				counting_stars(char const *pointer);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
int				calc_atoi(const char *str, int len, int counter);
int				ft_isspace(int chr);
void			ft_after(const char *pointer, va_list lista, struct var *global);
int				ft_final_len(void);
char			*ft_strjoin(char *s1, char const *s2);
void			ft_putsomething(bool type, char c, char *s, struct var *global);
char			*int_to_str(long int n, int len, char *result, int counter);
int				len_int(long long n);
int				power(long int n, int p);
int				hex_len(int n);
char			*ft_utoa(unsigned int n);
char			*ft_revstr(char *result);
size_t			ft_strlen(const char *pointer);
#endif