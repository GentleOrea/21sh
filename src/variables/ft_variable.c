/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:22:01 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/02 12:25:28 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_btree		**ft_variable(t_btree **val)
{
	static t_btree	**root = 0;

	if (!root)
		root = val;
	return (root);
}

int			ft_variableadd(char *name, void *data, int deep, int deported)
{
	t_variable	*var;
	t_btree		**root;
	t_btree		*pt;

	if (!(var = ft_variable_create(name, data, deep, deported)))
		return (-1);
	if (!(root = ft_variable(0)))
	{
		if (!(pt = btree_create_node((void*)var, RB_BLACK)))
		{
			ft_memdel((void**)&var);
			return (-1);
		}
		ft_variable(&pt);
	}
	else if (btree_insert_data(root, var, &ft_variablecmp))
	{
		ft_memdel((void**)&var);
		return (-1);
	}
	return (0);
}

t_variable	*ft_variableget(char *name)
{
	t_btree		**root;
	void		*var;
	t_variable	v;

	if (!name)
		return (0);
	if (!(root = ft_variable(0)))
		return (0);
	ft_bzero((void*)&v, sizeof(v));
	v.name = name;
	var = btree_search_item(*root, (void*)&v, &ft_variablecmp);
	if (!var || !((t_variable*)var)->name)
		return (0);
	return ((t_variable*)var);
}
