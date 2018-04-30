/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globbing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:05:07 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/30 18:56:48 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

void	true_sort(t_ls *begin, t_ls *to_add)
{
	while (begin->next)
		begin = begin->next;
	begin->next = to_add;
}

t_ls	*path_is_valid(t_glob *g, char *path, char *name)
{
	struct stat	st;
	t_ls		*tmp;

	if (g->dir->d_name[0] == '.' || !ft_match(name, *g->regex))
		return (NULL);
	name ? path = ft_strjoin(path, name) : 0;
	if (-1 == stat(path, &st) && lstat(path, &st) == -1)
	{
		ft_printf("error\n");
		//ls_error(path);
		ft_memdel((void**)&path);
		return (NULL);
	}
	mallcheck(tmp = (t_ls*)ft_memalloc(sizeof(t_ls)));
	tmp->is_dir = (st.st_mode & S_IFMT) == S_IFDIR ? 1 : 0;
	(st.st_mode & S_IFMT) == S_IFLNK ? lstat(path, &st) : 0;
	lstat(path, &st);
	tmp->path = path;
	tmp->name = ft_strdup(name);
	return (tmp);
}

t_ls	*end_sort(t_glob *g, t_ls *tmp, char *str)
{
	t_ls	*to_del;
	t_ls	*begin;

	g->regex = &g->regex[1];
	begin = *g->regex && **g->regex ? NULL : tmp;
	while (tmp)
	{
		if (*g->regex && **g->regex && tmp->is_dir
				&& ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
		{
			!tmp->path ? tmp->path = ft_strjoin(str, tmp->name) : 0;
			if (!begin)
				begin = recc(tmp->path, g->regex);
			else
				true_sort(begin, recc(tmp->path, g->regex));
		}
		to_del = tmp;
		tmp = tmp->next;
		if (!*g->regex)
			continue ;
		ft_memdel((void**)&to_del->name);
		ft_memdel((void**)&to_del->path);
		ft_memdel((void**)&to_del);
	}/*
	while(begin)
	{
		ft_printf("%s\n", begin->name);
		begin = begin->next;
	}*/
	return (begin);
}

t_ls	*sort_files(t_glob *g, t_ls *begin, char *str)
{
	t_ls	*tmp;
	char	link[256];

	tmp = begin;
	return (end_sort(g, begin, str));
}

t_ls	*sort_files2(t_glob *g, char *str)
{
	t_ls	*tmp;
	t_ls	*begin;

	begin = NULL;
	while (!begin && (g->dir = readdir(g->dire)))
		begin = path_is_valid(g, str, g->dir->d_name);
	while ((g->dir = readdir(g->dire)))
		if ((tmp = path_is_valid(g, str, g->dir->d_name)))
		{
			tmp->name = ft_strdup(g->dir->d_name);
			true_sort(begin, tmp);
		}
	return (begin);
}

t_ls	*recc(char *str, char **regex)
{
	t_ls		*begin;
	t_glob	g;

	ft_bzero(&g, sizeof(g));
	g.dire = opendir(str);
	g.regex = regex;
	if (!g.dire)
	{
		ft_printf("error\n");
		//		ls_error(str);
		return (NULL);
	}
	str = ft_strjoin(str, "/");
	begin = sort_files2(&g, str);
	begin ? begin = sort_files(&g, begin, str) : 0;
	//ft_memdel((void**)&str);
	closedir(g.dire);
	return (begin);
}

int main(int ac, char **av)
{
	t_ls *result;

	result = recc(av[1], ft_strsplit_comm("{test, tp}", "/"));
	while (result)
	{
		ft_printf("%s\n", result->path);
		result = result->next;
	}
}
