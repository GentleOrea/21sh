/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 15:17:29 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/03 15:26:15 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wctype.h>
# include "../../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_arg
{
	char	*flags;
	int		width;
	int		p;
	char	length;
	char	specifier;
	int		read;
	int		color;
	int		bg;
	int		type;
}				t_arg;

void			ft_affarg(t_arg *arg);

int				ft_printf(const char *format, ...);
int				ft_carrefour(va_list va, t_arg *arg, int read);
int				ft_carrefour_second(va_list va, t_arg *arg);
int				ft_carrefour_third(va_list va, t_arg *arg);

void			ft_spn(va_list va, t_arg *arg, int read);

t_arg			*ft_initarg(void);
t_arg			*ft_getarg(char *str, va_list va);
int				ft_freearg(t_arg **arg);
int				ft_addvalue(t_arg *arg, int *j, char *str, va_list va);
int				ft_add_flag(t_arg *arg, char c);
int				ft_add_width(t_arg *arg, char *str, va_list va);
int				ft_add_p(t_arg *arg, char *str, va_list va);
int				ft_add_length(t_arg *arg, char *str);
int				ft_add_color(t_arg *arg, char *str);
int				ft_add_bg(t_arg *arg, char *str);
int				ft_add_type(t_arg *arg, char *str);

int				ft_isflag(char c);
int				ft_iswidth(char *str);
int				ft_isp(char *str);
int				ft_islength(char *str);
int				ft_isspecifier(char c);
int				ft_iscolor(char *str);
int				ft_isbg(char *str);
int				ft_istype(char *str);

int				ft_lengthspe(t_arg *arg);
int				ft_lengths(va_list va, t_arg *arg);
int				ft_lengthss(va_list va, t_arg *arg);
int				ft_lengthp(va_list va, t_arg *arg);
int				ft_lengthd(va_list va, t_arg *arg);
int				ft_lengthdd(va_list va, t_arg *arg);
int				ft_lengtho(va_list va, t_arg *arg);
int				ft_lengthu(va_list va, t_arg *arg);
int				ft_lengthuu(va_list va, t_arg *arg);
int				ft_lengthx(va_list va, t_arg *arg);
int				ft_lengthxx(va_list va, t_arg *arg);
int				ft_lengthb(va_list va, t_arg *arg);
int				ft_lengthc(va_list va, t_arg *arg);
int				ft_lengthcc(va_list va, t_arg *arg);
int				ft_lengthe(va_list va, t_arg *arg);
int				ft_lengthee(va_list va, t_arg *arg);
int				ft_lengthf(va_list va, t_arg *arg);
int				ft_lengthff(va_list va, t_arg *arg);
int				ft_lengthg(va_list va, t_arg *arg);
int				ft_lengthgg(va_list va, t_arg *arg);
int				ft_lengtha(va_list va, t_arg *arg);
int				ft_lengthaa(va_list va, t_arg *arg);

void			ft_color(t_arg *arg);
void			ft_reset(t_arg *arg);
int				ft_write(char *str);
int				ft_printc(char c, t_arg *arg);
int				ft_prints(char *str);
int				ft_printd(char *str, t_arg *arg);
int				ft_printi(intmax_t nb, t_arg *arg);
int				ft_printp(void *p);
int				ft_printintmax(intmax_t nb, int written);

int				ft_writeto(const char *str, char c);
char			*ft_charsigned(char *str);
int				ft_expectedlength(intmax_t nb);
#endif
