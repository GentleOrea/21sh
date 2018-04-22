/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:00:01 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/17 16:01:02 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_power(size_t nb, size_t pow)
{
	if (pow > 12)
		return (0);
	if (pow == 0)
		return (1);
	return (nb * ft_power(nb, pow - 1));
}
