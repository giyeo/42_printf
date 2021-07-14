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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_var
{
	int			final_size;
	int			crt;
	int			check;
	int			right_zero;
	bool		malloc_used;
	bool		precision_pass;
	bool		noPrecVal;
	bool		zero_before;
	bool		zero_string;
	bool		error;
	bool		abort;
	bool		prec_print_minus;
	bool		print_a_minus;
	bool		flag_check;
	long int	flag_minus;
	long int	flag_zero;
	long int	width_size;
	long int	prec_size;
	long int	o_zero;
	long int	precision_x;
}	t_var;

int				ft_minus_zero(int n, const char *pointer, t_var *global);
int				ft_minus_pzero(int n, t_var *global);
int				ft_minus_star(int n, va_list lista, t_var *global);
int				ft_minus_isdigit(int n, const char *pointer,
					t_var *global);
int				flag_abort(int n, t_var *global);
void			flag_check(va_list lista, t_var *global);
int				flag_calc(int n, t_var *global, const char *pointer);
void			flag_minus(t_var *global);
int				until_type(const char *pointer);
int				prec_calc(int n, t_var *global, int check,
					const char *pointer);
int				prec_abort_two(int n, t_var *global);
int				prec_set(int n, t_var *global);
int				prec_noprec(int n, t_var *global);
int				prec_abort_one(t_var *global);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strdup(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_prec_n_bt_prec(t_var *global,
					int is_unsigned);
int				how_many_zeros(const char *pointer);
int				case_d_mzero(int d, t_var *global);
int				len_prec_error_hand(int d, t_var *global);
int				ft_len_after(const char *format);
char			*pointeraddress(unsigned long int n);
char			*ft_strdup(const char *s);
void			ft_parameter_s(char *pointer, t_var *global);
void			ft_parameter_p(void *pointer, t_var *global);
int				ft_is_precision(const char *pointer, va_list lista,
					t_var *global);
int				ft_prec_error_hand(int d, t_var *global);
void			ft_prec_error_hand_c(t_var *global);
int				ft_prec_error_hand_u(unsigned int u,
					t_var *global);
int				ft_prec_error_hand_x(int parameter, unsigned int u,
					t_var *global);
int				ft_is_flag(const char *pointer, va_list lista,
					t_var *global);
int				ft_is_width(const char *pointer, va_list lista,
					t_var *global);
int				ft_printf(const char *format, ...);
char			*ft_itoa(int n);
char			*ft_htoa_upper(unsigned int n);
char			*ft_htoa_lower(unsigned int n);
int				ft_isdigit(int argument);
int				is_type(char n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
int				calc_atoi(const char *str, int len, int counter);
int				ft_isspace(int chr);
void			ft_after(const char *pointer, va_list lista,
					t_var *global);
int				ft_final_len(void);
char			*ft_strjoin(char *s1, char const *s2);
void			ft_putsomething(bool type, char c, char *s,
					t_var *global);
char			*int_to_str(long int n, int len, char *result, int counter);
int				len_int(long long n);
int				power(long int n, int p);
int				hex_len(unsigned long int n);
char			*ft_utoa(unsigned int n);
char			*ft_revstr(char *result);
size_t			ft_strlen(const char *pointer);
#endif