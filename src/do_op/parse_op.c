/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:06:05 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/17 16:39:09 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define OP_CREMENT "--++"
#define OP_COMP "== != <= >= < >"
#define OP_ASSIGN "= *= /= %= += -= <<= >>= &= ^= |="
#define OP_BIT "<< >> | || && & ^ ~"
#define ALL_OP "= *= /= %= += -= <<= >>= &= ^= |= -- ++"

#include "../../includes/sh.h"

int		is_legal(char c)
{
	if (!ft_isalnum(c))
		return (0);
	return (1);
}

#define A 0
#define O 1
#define B 2
#define RES 3
int		is_local(char *str)
{
	if (1)
		return (1);
	else if (2)
		return (0);
}

int	 parse_op(char *str)
{
	int 		i;
	int			is_digit;
	int			is_set[3];
	int			val[4];
	char	**op_tb;

	op_tb = ft_custom_split(str, /*OP_CREMENT*/NULL);
	while (op_tb[i])
	{
		if (get_sep((char*)&str[i], NULL) > 0)
			return(0) ;
		else
		{
			is_digit = (!op_tb[ft_occiter2(op_tb[i], ft_isdigit)]);
			if (!is_set[A] && ++is_set[A])
				val[A] = is_digit ? ft_atoi(op_tb[i]) : is_local(op_tb[i]);
			else if (is_set[O])
				exit(EXIT_FAILURE);
			else if (++is_set[B])
				val[B] = is_digit ? ft_atoi(op_tb[i]) : is_local(op_tb[i]);
			else
				exit(0);
		}
		is_set[B] ? val[RES] += 
	}
	return (val[RES]);
}
