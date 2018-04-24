/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:39:03 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/20 12:34:17 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*cra;

	if (!alst)
		return ;
	if (!(tmp = *alst))
		*alst = NULL;
	while (tmp)
	{
		cra = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = cra;
	}
}
