/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:39:37 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/14 14:39:38 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	**alst;
	t_list	*tmp;

	if (!(alst = (t_list **)malloc(sizeof(t_list *))))
		return (NULL);
	if (!lst)
		return (NULL);
	if (!(*alst = f(lst)))
		return (NULL);
	tmp = *alst;
	while (lst->next)
	{
		if (!(tmp->next = f(lst->next)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (*alst);
}
