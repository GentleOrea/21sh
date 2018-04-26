/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:24:42 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/26 16:49:29 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
#define GLOB_H
#include "21sh.h"

typedef struct	s_glob
{
	char			b;
	char			m;
	char			m_files;
	int				op;
	DIR				*dire;
	struct dirent	*dir;
	int				nb_block;
}				t_glob;

typedef struct	s_ls
{
	char			is_dir;
	char			b;
	char			type;
	char			*path;
	char			*name;
	struct s_ls		*next;
}				t_ls;

t_ls	*path_is_valid(t_glob *g, char *path, char *name, int op);
void	end_sort(t_glob *g, t_ls *tmp, char *str, int op);
void	sort_files(t_glob *g, t_ls *begin, char *str, int op);
t_ls	*sort_files2(t_glob *g, char *str, int op);
void	recc(char *str, int op);
#endif
