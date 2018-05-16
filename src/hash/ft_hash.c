/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:57:58 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/16 11:36:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

unsigned long	hash(char *str)
{
	unsigned long	hash;
	unsigned long	c;

	if (!str)
		return (0);
	hash = 5381;
	while ((c = (unsigned long)*str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

int				ft_set_hash(t_btree **begin, char *key, char *value)
{
	char	**content;
	t_btree *tmp;

	if (!key || !value)
		return (-1);
	if (!*begin || !(tmp = btree_search_item(*begin, &key, ft_hashcmp)))
	{
		if (!(content = (char**)ft_memalloc(2 * sizeof(char*))))
			return (-1);
		content[0] = ft_strdup(key);
		content[1] = ft_strdup(value);
		btree_insert_data(begin, content, ft_hashcmp);
		return (1);
	}
	ft_memdel((void**)&key);
	ft_memdel((void**)&(((char**)tmp->item)[1]));
	((char**)tmp->item)[1] = value;
	return (1);
}

char			*ft_get_hash(t_btree **hash_tb, char *key)
{
	unsigned long	index;
	t_btree			*tmp;

	index = hash(key) % HASH_SIZE;
	if (!(tmp = hash_tb[index]))
		return (NULL);
	tmp = btree_search_item(tmp, &key, ft_hashcmp);
	return (tmp && tmp->item ? ((char**)(tmp->item))[1] : NULL);
}
