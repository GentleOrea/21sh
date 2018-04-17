/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:40:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/17 10:59:15 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "21sh.h"

#define QUOTES "\"\'"
#define H_SEP ";&\n"
#define HERE ";|\n"

#define ALL (char *[11]){"||", "&&", "|", "&", ";", ">>", "<<", "<", ">" }
#define SEP (char *[6]){"||", "&&", "|", "&", ";"}
#define REDI (char *[5]){">>", "<<", "<", ">"}

/*
** strnstr pour un tableau passé en param
** renvoie la taille de la chaine si trouvée dans le tab sinon 0
*/

char		is_sep(char *str, t_parser *par, char **tab)
{
	int		i;
	char	len;

	i = -1;
	while (tab[++i] && !ft_strnstr(str, tab[i], len = ft_strlen(tab[i])))
		;
	tab[i] ? ft_strcpy(par->sep, tab[i]) : 0;
	return (tab[i] ? len : 0);
}

/*
** les deux fonctions en dessous permettent de compter le nombre de here_doc
** split les commandes en fonction de tout les type de separateur.
** Pas super clean mais évite d'allouer de la mem
** Gere les erreurs de parsing, ne gere (surement) pas toutes les erreurs
*/

int		sizeof_comm(char *str, t_parser *par)
{
	int		i;
	char	sep;
	char	hdoc;
	char	q;

	i = 0;
	sep = 0;
	while (str[i] && !(sep = is_sep(&str[i], par, SEP)))
	{
		if ((hdoc = is_sep(&str[i], par, REDI)) )
		{
			par->doc_h += ((ft_strnstr(&str[i], ">>", 2) && (i += hdoc)) ? 1 : 0);
			while (str[i] == ' ')
				i++;
			if (!(hdoc = 0) && is_sep(&str[i], par, ALL))
				return (-1);
		}
		if (ft_isin(str[++i], QUOTES) && (q = str[i] == '"' ? '"' : '\''))
			while (str[i] && str[++i] != q)
				;
	}
	if (str[i] && (str[i] == ';' || ft_strnstr(&str[i], ";;", 2)))
		return (!ft_strnstr(&str[i], ";;", 2) ? i |1 : -1);
	return (i || !str[i] ? i + sep : -1);
}

int		count_comm(t_parser *par, char *str)
{
	int		i;
	int		sep;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		sep = sizeof_comm(&str[i], par);
		if (sep < 0)
			return (-ft_printf("yosh: parse error near %s", par->sep));
		i += sep;
	}
		ft_printf("ici\n");
	return (par->doc_h);
}


int main(int ac, char **av)
{
	t_parser	par;
	(void)ac, (void)av;(void)par;
	t_comm co;
	hard_split(&co, av[1]);
}
