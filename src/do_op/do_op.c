/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:08:36 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/21 11:08:36 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

#define A 0
#define O 1
#define B 2
#define RES 3
# define OPE (char *[16]){"<<", ">>", "||", "&&","**",  "|", "&", "^", "~", "+", "-", "/", "*", "%"}
#define OP_CREMENT (char *[3]){"--", "++"}

int		do_op(int is_set[0][4], int *val)
{
	int i;
	static int		(**f_op)(int, int) = 0;

	if (!f_op)
		f_op = f_opget();
	i = -1;
	//ft_printf("[%d %d %d]\n",is_set[0][O], is_set[0][A], is_set[0][B]);
	//ft_printf("%d %d %d\n",is_set[0][RES], val[A], val[B]);
	if (is_set && !is_set[0][B])
		return(0);
	is_set ? ft_bzero(*is_set, sizeof(is_set[0])) : 0;
	is_set[0][RES] = 1;
	return (f_op[val[O]](val[A], val[B]));
}

int		is_local(char *str);

int		get_value(char *str)
{
	if (!(ft_occiter2(str, ft_isdigit) < 0))
		return(ft_atoi(str));
	return (is_local(str));
}

int		*set_op(char **op_tb, int i)
{
//	int		i;
	int		val[4];

	if (!ft_str_isdigit(op_tb[i]))
		if (get_sep(op_tb[i], OP_CREMENT) < 0)
			if (!is_local(op_tb[i + 1]))
				exit(-ft_printf("error\n"));
	return (NULL);
}

void	get_divmul(char **op_tb, int **tab_res)
{
	int		i;
	int		val[4];
	
	while (op_tb[i])
	{
		if (*op_tb[i] == '*' || *op_tb[i] == '/')
		{
	//		tab_res[i / 2] = do_op(NULL, OP_CREMENT);
		}
	}
}

int		calc_op(char **op_tb)
{
	int 		i;
	int			is_digit;
	int			is_set[4];
	int			val[4];

	i = -1;
	ft_bzero(&is_set, sizeof(is_set));
	while (op_tb[++i])
	{
		if (!is_set[O] && (val[O] = get_sep(op_tb[i], OPE)) >= 0 && ++is_set[O])
			continue ;
		//ft_printf("RES[%d]A[%d]O[%d]B[%d][%d]%s\n",val[RES],val[A], is_set[O], is_set[B], i, op_tb[i]);
		if (is_set[RES] && (is_set[A] = 1))
			val[A] = val[RES];
		if (!is_set[A] && ++is_set[A])
			val[A] = get_value(op_tb[i]);
		else if (!is_set[O])
			exit(-ft_printf("no op\n"));
		else if (++is_set[B])
			val[A] = get_value(op_tb[i]);
		else
			exit(-ft_printf("invalid\n"));
		val[RES] = do_op(&is_set, val);
	}
	return (val[RES]);
}
