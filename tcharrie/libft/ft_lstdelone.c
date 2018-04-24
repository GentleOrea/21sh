/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:37:25 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/20 12:30:58 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
		del((*alst)->content, (*alst)->content_size);
	if (alst)
	{
		free(*alst);
		*alst = NULL;
	}
}
