/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:57:20 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 11:15:43 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int pow)
{
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (0);
	return (nb * ft_power(nb, pow - 1));
}
