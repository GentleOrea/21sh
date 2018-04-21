/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getentry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:45:03 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/15 13:57:06 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
** Cette fonction recupere l'entree de l'utilisateur qu'elle stock dans line
** A la fin de l'execution, le contenu d'une commande est retourne sous
** la forme {commande, here doc}
** S'il restait des commandes, elles sont stockees dans line
** Sinon line = 0
**
** La chaine de commande renvoyee par la fonction est correctement formatee
**
** Correspondance de val :
**		0 == Position du curseur
**		1 == nb de char affichés au début pour le spécial ligne
**		2 == nombre de here doc
**		3 == Nombre de here doc au dernier décompte
**		4 == 1 si j'ecris dans la commande || 0 si j'ecris dans un here doc
**		5 == La zone du string jusqu'a laquelle je peux remonter (dans line)
**			(souvent 0, sauf apres un << si y'a une commande non fini)
**		6 == Largeur du terminal a la derniere maj
**		7 == Hauteur du terminal a la derniere maj
**		8 == Place dans l'historique de la ligne (0 == cache)
*/

t_line	ft_getentry(void)
{
	static char	*line = 0;
	int			val[12];
	t_line		ligne;

	ft_memset((void*)val, 0, sizeof(val));
	val[6] = tgetnum("co");
	val[7] = tgetnum("li");
	while (!line)
		line = ft_init_aff(val);
	ligne.line = line;
	ligne.eof = 0;
	val[9] = ft_read(&ligne, val);
	if (!ligne.line)
		return (ligne);
	while (ligne.line[val[9]] && ligne.line[val[9]] != '\n')
		val[9]++;
	if (ligne.line[val[9]])
		line = ft_strdup(&(ligne.line[val[9]]));
	else
		line = 0;
	return (ligne);
}

int	main(int ac, char **av, char **env)
{
	ft_initsig();
	ft_init_terminal_data(env);
	ft_setattr();
	while (1)
	{
		ft_getentry();
	}
}
