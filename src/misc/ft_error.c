/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:53:12 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 13:04:36 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	ft_fatal(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

char	*ft_conversion_error(int code)
{
	if (code == MALLOC_ERR)
		ft_putstr_fd(MALLOC_ERR_MSG, 2);
	else if (code == PARSING_ERROR_3)
		ft_putstr_fd(PARSING_ERROR_3_MSG, 2);
	else if (code == PARSING_ERROR_4)
		ft_putstr_fd(PARSING_ERROR_4_MSG, 2);
	return (0);
}

void	ft_errorlog(char *msg)
{
	int	fd;
	int	i;

	if (!msg)
		return ;
	if ((fd = open(LOGFILE, O_WRONLY | O_APPEND)) < 0)
		return ;
	i = ft_strlen(msg);
	msg[i] = '\n';
	write(fd, msg, i + 1);
	close(fd);
}
