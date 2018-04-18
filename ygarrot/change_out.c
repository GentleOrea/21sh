/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:08:04 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/18 18:21:45 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "21sh.h"

/*
** Ce programme effectue les changements pour x>fd
** Le format est le meme pour x>&fd (Simplement ne pas ouvrir le fichier)
*/

int		redi(char **av, int type)
{
	int		fd;
	char	c;
	int		x;

	if ()
	if ((fd = open(av[0], O_WRONLY)) <= 0)
	{
		dprintf(2, "Failed to open OUT_FILE\n");
		return (0);
	}
	if (dup2(fd, x) == -1)
	{
		dprintf(2, "Failed to dup2\n");
		exit(1);
	}
	write(x, av[1], strlen(av[1]));
	return (0);
}
