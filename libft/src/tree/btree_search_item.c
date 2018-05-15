/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:51:38 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/15 18:13:48 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*found;

	found = NULL;
	if (root->left)
		found = btree_search_item(root->left, data_ref, cmpf);
	if (!found && !(cmpf(data_ref, root->item)))
		found = root;
	if (!found && root->right)
		found = btree_search_item(root->right, data_ref, cmpf);
	return (found);
}
