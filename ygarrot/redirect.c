/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:08:04 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/19 17:09:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "21sh.h"

/*
** Ce programme effectue les changements pour x>fd
** Le format est le meme pour x>&fd (Simplement ne pas ouvrir le fichier)
*/

int		redi(t_redi redi)
{
	int		fd;
	int		flag;

	if (redi.type <= 2 && redi.path[0] == '&')
	{
		if (!ft_strcmp(redi.path, "&-"))
			return (close(redi.n));
	}
	flag = O_WRONLY | O_CREAT | (redi.type | 8 ? O_APPEND : 0);
	if ((fd = open(redi.path, flag)) <= 0)
	{
		dprintf(2, "Failed to open OUT_FILE\n");
		return (0);
	}
	if (dup2(fd, redi.n) == -1)
	{
		dprintf(2, "Failed to dup2\n");
		exit(1);
	}
	return (0);
}
