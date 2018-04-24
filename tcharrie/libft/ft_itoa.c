/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:40:24 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/27 10:11:29 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*dst;
	int		signe;
	int		size;

	size = 1;
	signe = (int)(n < 0 ? 1 : 0);
	while (n / ft_power(10, size) != 0 && n != -2147483648)
		size++;
	if (n >= 1000000000 || n <= -1000000000)
		size = 10;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1 + signe))))
		return (NULL);
	if (signe)
		dst[0] = '-';
	dst[signe + size] = '\0';
	size--;
	if (n == 0)
		dst[0] = (char)'0';
	while (n != 0)
	{
		dst[signe + size] = (char)(n < 0 ? -(n % 10) + '0' : n % 10 + '0');
		size--;
		n /= 10;
	}
	return (dst);
}
