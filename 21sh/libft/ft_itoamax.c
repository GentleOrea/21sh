/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoamax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:34:59 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/30 13:44:36 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoamax(intmax_t n)
{
	char		*dst;
	int			signe;
	int			size;
	uintmax_t	nb;

	nb = n < 0 ? -n : n;
	size = 1;
	signe = (int)(n < 0 ? 1 : 0);
	while ((n /= 10) != 0)
		size++;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1 + signe))))
		return (NULL);
	if (signe)
		dst[0] = '-';
	dst[signe + size--] = '\0';
	if (nb == 0)
		dst[0] = (char)'0';
	while (nb != 0)
	{
		dst[signe + size--] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	return (dst);
}
