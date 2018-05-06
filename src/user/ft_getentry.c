/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getentry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:45:03 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 13:48:25 by tcharrie         ###   ########.fr       */
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
**		2 == Nombre de caracteres selectionnes
**		3 == Fin de line->eof
**		4 == 1 si j'ecris dans la commande || 0 si j'ecris dans un here doc
**		5 == La zone du string jusqu'a laquelle je peux remonter (dans line)
**			(souvent 0, sauf apres un << si y'a une commande non fini)
**		6 == Largeur du terminal a la derniere maj
**		7 == Hauteur du terminal a la derniere maj
**		8 == Place dans l'historique de la ligne (0 == cache)
*/

t_line	ft_getentry(void)
{
	int			val[13];
	t_line		ligne;

	ft_memset((void*)val, 0, sizeof(val));
	val[4] = 1;
	ligne.line = ft_init_aff(val);
	ligne.size_line = val[0] + 1;
	ligne.size_eof = 2;
	if (!(ligne.eof = (char*)ft_memalloc(2)))
		ft_strdel(&(ligne.line));
	else if (ft_read(&ligne, val) == -1)
	{
		ft_strdel(&(ligne.line));
		ft_strdel(&(ligne.eof));
	}
	else
	{
		ft_history_add(ft_history_parser(&(ligne.line)[val[1]]));
		ft_heredoc_purge(ligne.eof, ligne.size_eof);
	}
	ft_history_cache(0, CODE_RESET);
	return (ligne);
}
/*
int	main(int ac, char **av, char **env)
{
	t_line	line;

	ft_initsig();
	ft_init_terminal_data(env);
	ft_setattr();
	while (1)
	{
		line = ft_getentry();
		while (line.line == 0)
			line = ft_getentry();
	}
}*/
