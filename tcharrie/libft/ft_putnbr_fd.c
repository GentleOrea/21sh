/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:36:59 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/14 17:13:55 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n < -9)
			ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd((char)(n < 0 ? '0' - (n % 10) : '0' + (n % 10)), fd);
	}
	else if (n < 10)
		ft_putchar_fd((char)('0' + (n % 10)), fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((char)('0' + (n % 10)), fd);
	}
}
