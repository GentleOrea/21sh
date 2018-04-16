/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:30:38 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/16 15:24:29 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

#define QUOTES "\"\'"
#define DEL ";&\n"
#define HERE ";|\n"

#define ALL (char *[11]){"||", "&&", "|", "&", ";", ">>", "<<", "<", ">" }
#define SEP (char *[6]){"||", "&&", "|", "&", ";"}
#define REDI (char *[5]){">>", "<<", "<", ">"}

char		is_sep(char *str, t_parser *g, char **tab)
{
	int		i;
	char	len;

	i = -1;
	while (tab[++i] && !ft_strnstr(str, tab[i], len = ft_strlen(tab[i])))
		;
	//ft_printf("%d\n", i);
	tab[i] ? ft_strcpy(g->sep, tab[i]) : 0;
	return (tab[i] ? len : 0);
}

int		sizeof_comm(char *str, t_parser *g)
{
	int		i;
	char	sep;
	char	hdoc;
	char	q;

	i = 0;
	sep = 0;
	while (str[i] && !(sep = is_sep(&str[i], g, SEP)))
	{
		if ((hdoc = is_sep(&str[i], g, REDI)) )
		{
			g->doc_h += ((ft_strnstr(&str[i], ">>", 2) && (i += hdoc)) ? 1 : 0);
			while (str[i] == ' ')
				i++;
			if (!(hdoc = 0) && is_sep(&str[i], g, ALL))
				return (-1);
		}
		if (ft_isin(str[++i], QUOTES) && (q = str[i] == '"' ? '"' : '\''))
			while (str[i] && str[++i] != q)
				;
	}
	if (str[i] == ';' || ft_strnstr(&str[i], ";;", 2))
		return (!ft_strnstr(&str[i], ";;", 2) ? 1 : -1);
	ft_printf("sizeof : [%d][%d]%s\n", i,sep, str);
	return (i || !str[i] ? i + sep : -1);
}


int		count_comm(t_parser *g, char *str)
{
	int		i;
	int		mal;
	int		sep;

	mal = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		sep = sizeof_comm(&str[i], g);
		if (sep < 0)
			return (-ft_printf("yosh: parse error near %s", g->sep));
		i += sep;
		mal++;
	}
	return (g->doc_h);
}

char	**split_cli(char *str, int mal)
{
	int	i;
	char	**ret;

	if (!(ret = (char**)ft_memalloc(mal * sizeof(char*))))
		return (NULL);
	mal = 1;
	i = 0;
	while (str[i])
	{
		if (!(ret[i] = (char*)ft_memalloc(sizeof(char))))
			return (NULL);
	}
	return (ret);
}


int main(int ac, char **av)
{
	t_parser	g;
	(void)ac, (void)av;
	
;	ft_printf("%d\n", count_comm(&g, av[1]));
}
