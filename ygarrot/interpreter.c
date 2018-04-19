/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:50:01 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/19 16:28:37 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	epur_tab(char **tab, t_tab *list, int len)
{
	int		i;
	t_tab	*to_del;

	i = 0;
	ft_memdel((void**)&tab);
	mallcheck(tab = (char**)ft_memalloc(len * sizeof(char*)));
	while (list)
	{
		tab[i] = list->str;
		to_del = list;
		list = list->next;
		ft_memdel((void**)&to_del);
	}
}

static void	add_comm(t_inter inte, char *str)
{
	t_tab	*to_add;
	t_tab	*temp;

	mallcheck(to_add = (t_tab*)ft_memalloc(sizeof(t_tab)));
	to_add->str = str;
	temp = inte.tab;
	if (!temp)
	{
		inte.tab = to_add;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = to_add;
}

static void	add_redi(t_inter inte, char **tab, int *i)
{
	t_redi	*redi;
	t_redi	*temp;
	int		len;

	mallcheck(redi = (t_redi*)ft_memalloc(sizeof(t_redi)));
	redi->n = ft_atoi(*tab);
	while (ft_isdigit(**tab))
		tab++;
	redi->type = get_sep(*tab, REDI);
	len = ft_strlen(REDI[redi->type]);
	if (!(tab[0][len]) && ++*i)
		redi->path = ft_strdup(tab[1]);
	else
		redi->path = ft_strdup(&*tab[len]);
	temp = inte.redi;
	if (!temp)
	{
		inte.redi = redi;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = redi;
}

void	split_co(t_comm *c)
{
	t_inter	inte;
	t_comm	*tmp;
	int		len;
	int		i;

	tmp = c;
	ft_bzero(&inte, sizeof(inte));
	while (tmp)
	{
		inte.cli = ft_strsplit_comm(tmp->comm, " ");
		i = -1;
		len = 0;
		while (inte.cli[++i])
		{
			if (search_op(inte.cli[i], REDI) >= 0)
				add_redi(inte, &inte.cli[i], &i);
			else if (++len)
				add_comm(inte, inte.cli[i]);
		}
		epur_tab(inte.cli, inte.tab, len);
		//exec_cli();
		tmp = tmp->next;
	}
}

void	exec_cli(t_inter inter)
{
	t_redi *redi;

	while (redi)
	{
		//exec redi
		redi = redi->next;
	}
	//execve inter.tab[0] &inter.tab[0]
}
