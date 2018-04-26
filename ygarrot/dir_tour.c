/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globbing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:05:07 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/26 16:49:30 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

void	true_sort(t_ls *begin, t_ls *to_add)
{
	while (begin->next)
		begin = begin->next;
	begin->next = to_add;
}

t_ls	*path_is_valid(t_glob *g, char *path, char *name, int op)
{
	struct stat	st;
	t_ls		*tmp;

	if (!g->b && (!(op & 4) && g->dir->d_name[0] == '.'))
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

void	end_sort(t_glob *g, t_ls *tmp, char *str, int op)
{
	t_ls	*to_del;

	while (tmp)
	{
		if ((g->b && tmp->is_dir) || (!g->b && ((op & 2) && tmp->type == 4
				&& ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))))
		{
			!tmp->path ? tmp->path = ft_strjoin(str, tmp->name) : 0;
			!tmp->b ? ft_printf("\n") : 0;
			ft_printf("%s:\n", tmp->path) ;
			recc(tmp->path, op);
		}
		to_del = tmp;
		tmp = tmp->next;
		ft_memdel((void**)&to_del->name);
		ft_memdel((void**)&to_del->path);
		ft_memdel((void**)&to_del);
	}
}

void	sort_files(t_glob *g, t_ls *begin, char *str, int op)
{
	t_ls	*tmp;
	char	link[256];

	ft_bzero(link, sizeof(link));
	tmp = begin;
	while (tmp && tmp->name)
	{
		ft_printf("%s", tmp->name);
		if (readlink(tmp->path, link, 255) > 0 && (op & 1))
			ft_printf(" -> %s", link);
		ft_printf("\n");
		begin->b = 0;
		tmp = tmp->next;
	}
	end_sort(g, begin, str, op);
}

t_ls	*sort_files2(t_glob *g, char *str, int op)
{
	t_ls	*tmp;
	t_ls	*begin;

	begin = NULL;
	while (!begin && (g->dir = readdir(g->dire)))
		begin = path_is_valid(g, str, g->dir->d_name, op);
	while ((g->dir = readdir(g->dire)))
		if ((tmp = path_is_valid(g, str, g->dir->d_name, op)))
		{
			tmp->name = ft_strdup(g->dir->d_name);
			true_sort(begin, tmp);
		}
	/*while(begin)
	{
		ft_printf("%s\n", begin->name);
		begin = begin->next;
	}*/
	return (begin);
}

void	recc(char *str, int op)
{
	t_ls		*begin;
	t_glob	g;

	ft_bzero(&g, sizeof(g));
	g.dire = opendir(str);
	if (!g.dire)
	{
		ft_printf("error\n");
		//		ls_error(str);
		return ;
	}
	str = ft_strjoin(str, "/");
	begin = sort_files2(&g, str, op);
	begin ? sort_files(&g, begin, str, op) : 0;
	ft_memdel((void**)&str);
	closedir(g.dire);
}

int main(int ac, char **av)
{
	recc(av[1], 0);
}
