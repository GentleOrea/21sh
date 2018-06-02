/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:22:01 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/02 14:05:19 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_btree		**ft_variable(t_btree **val)
{
	static t_btree	**root = 0;

	if (!root)
		root = ft_memalloc(sizeof(t_btree*));
	if (!root)
		return (0);
	if (!*root)
		root[0]->item = (void*)ft_variable_create(ft_strdup(""), 0, 0, 0);
	if (!*root || !((t_variable*)(root[0]->item))->name)
	{
		ft_variabledel((t_variable*)(root[0]->item));
		ft_memdel((void**)&root);
		return (0);
	}
	return (root);
}

int			ft_variableadd(char *name, void *data, int deep, int deported)
{
	t_variable	*var;
	t_btree		**root;
	t_btree		*pt;

	if (!(root = ft_variable(0)))
		return (-1);
	if (!*root)
		return (-1);
	if (!(var = ft_variable_create(name, data, deep, deported)))
		return (-1);
	else if (btree_insert_data(root, var, &ft_variablecmp, &ft_variabledel))
	{
		ft_variabledel(var);
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
	if (!var)
		return (0);
	return ((t_variable*)var);
}
