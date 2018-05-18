/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:59:18 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/18 15:05:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

#define A 0
#define O 1
#define B 2
#define RES 3
# define OPE (char *[14]){"<<", ">>", "||", "&&","**",  "|", "&", "^", "~", "+", "-", "/", "*", "%"}
#define OP_CREMENT {"--", "++"}
void		do_op(int is_set[0][3], int *val)
{
	int i;
	static int		(**f_op)(int, int) = 0;

	if (!f_op)
		f_op = f_opget();
	i = -1;
	if (!*is_set[B])
		return ;
	val[RES] += f_op[val[O]](val[A], val[B]);
	ft_bzero(*is_set, sizeof(*is_set));
}

int		is_local(char *str);
int		calc_op(char **op_tb)
{
	int 		i;
	int			is_digit;
	int			is_set[3];
	int			val[4];

	while (op_tb[i])
	{
		if (!is_set[O] && (val[O] = get_sep((char*)&op_tb[i], OPE)) >= 0)
			continue ;
		is_digit = (!op_tb[ft_occiter2(op_tb[i], ft_isdigit)]);
		if (!is_set[A] && ++is_set[A])
			val[A] = is_digit ? ft_atoi(op_tb[i]) : is_local(op_tb[i]);
		else if (!is_set[O])
			exit(EXIT_FAILURE);
		else if (++is_set[B])
			val[B] = is_digit ? ft_atoi(op_tb[i]) : is_local(op_tb[i]);
		else
			exit(0);
		do_op(&is_set, val);
	}
	return (val[O]);
}
