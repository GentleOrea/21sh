/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:25:21 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/12 13:41:45 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*data;
	size_t	t;

	if (!(data = (void *)malloc(size)))
		return (NULL);
	t = 0;
	while (t < size)
	{
		((char *)data)[t] = 0;
		t++;
	}
	return (data);
}
