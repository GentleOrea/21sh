/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variablecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:09:41 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/08 15:16:35 by tcharrie         ###   ########.fr       */
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
	if (left->deep < right->deep)
		return (-1);
	if (right->deep < left->deep)
		return (1);
	if (left->deep == 1)
		return (ft_strcmp(left->str, right->str));
	i = 0;
	while ((left->array)[i] && (right->array)[i])
	{
		if ((cmp = ft_strcmp((left->array)[i], (right->array)[i])) != 0)
			return (cmp);
		i++;
	}
	return (((right->array)[i]) ? (-1) : ((left->array)[i] != 0));
}
