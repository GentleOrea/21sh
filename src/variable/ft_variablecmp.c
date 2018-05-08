/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variablecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:09:41 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/08 15:23:49 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_variablecmp(void *l, void *r)
{
	t_variable	*left;
	t_variable	*right;
	int			i;
	int			cmp;

	if (!l || !r)
		return (0);
	left = (t_variable*)left;
	right = (t_variable*)right;
	return (ft_strcmp(left->name, right->name));
}
