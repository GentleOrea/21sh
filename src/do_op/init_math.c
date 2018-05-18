/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:16:04 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/18 14:35:04 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int (**f_opget(void))(int, int)
{
	static int		(**f_op)(int, int);
	
	f_op[0] = ft_mult;
	f_op[0] = ft_summ;
	f_op[0] = ft_div;
	f_op[0] = ft_sub;
	f_op[0] = ft_mod;
	f_op[0] = ft_left_shift;
	f_op[0] = ft_right_shift;
	f_op[0] = ft_log_or;
	f_op[0] = ft_log_and;
	f_op[0] = ft_and;
	f_op[0] = ft_or;
	f_op[0] = ft_xor;
	f_op[0] = ft_bitneg;
	return (f_op);
}

