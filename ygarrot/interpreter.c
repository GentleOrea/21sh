/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:27:49 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/04 19:50:33 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	add_comm(t_com *com, char *str)
{
	t_tb	*to_add;
	t_tb	*temp;

	mallcheck(to_add = (t_tb*)ft_memalloc(sizeof(t_tb)));
	if (!(to_add->glob = ft_glob(str, 0)))
		to_add->str = str;
	else
		ft_memdel((void**)&str);
	com->len += to_add->str ? 1 : to_add->glob->nb_paths;
	temp = com->tb;
	if (!temp)
	{
		com->tb = to_add;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = to_add;
}

void	add_redi(t_com *com, char **tb, int *i)
{
	t_redi	*redi;
	t_redi	*temp;
	int		len;

	mallcheck(redi = (t_redi*)ft_memalloc(sizeof(t_redi)));
	redi->fd[0] = ft_isdigit(**tb) ? ft_atoi(*tb) : -1;
	while (**tb && ft_isdigit(**tb))
		++*tb;
	redi->type = get_sep(*tb, REDI);
	len = ft_strlen(REDI[redi->type]);
	if (!(tb[0][len]) && ++*i)
		redi->path = ft_strdup(tb[1]);
	else
		redi->path = ft_strdup(&tb[0][len]);
	temp = com->redi;
	if (!temp)
	{
		com->redi = redi;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = redi;
}

void norm(t_parser *tmp, t_com *com)
{
	int		i;
	char	*free;

	if (tmp->next)
		mallcheck(com->next = (t_com*)ft_memalloc(sizeof(t_com)));
	if (!tmp->comm)
		return ;
	mallcheck(com->cli = ft_strsplit_comm(tmp->comm, " "));
	i = -1;
	while (com->cli[++i])
	{
		free = com->cli[i];
		//com->cli[i] = ft_find_and_replace(free, "\\", 1);
		if (search_op(com->cli[i], REDI) >= 0)
			add_redi(com, &com->cli[i], &i);
		else
			add_comm(com, com->cli[i]);
		//ft_memdel((void**)&free);
	}
}

void	split_co(t_shell *sh, t_parser *tmp)
{
	t_com	*com;
	t_parser *to_del;

	mallcheck(com = (t_com*)ft_memalloc(sizeof(t_com)));
	sh->com = com;
	while (tmp)
	{
		norm(tmp, com);
		com->type = tmp->type;
		to_del = tmp;
		tmp = tmp->next;
		com = com->next;
		ft_memdel((void**)&to_del->comm);
		ft_memdel((void**)&to_del);
	}
	sort_comm(sh, sh->com);
}
