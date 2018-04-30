/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:24:42 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/30 18:56:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
#define GLOB_H
#include "21sh.h"

typedef struct	s_glob
{
	char			b;
	DIR				*dire;
	char			**regex;
	struct dirent	*dir;
	int				i;
}				t_glob;

typedef struct	s_ls
{
	char			is_dir;
	char			b;
	char			*path;
	char			*name;
	struct s_ls		*next;
}				t_ls;

int ft_strlento_comm(char *str, char *to_find);
int ft_match(char *str, char *to_match);
char	*enclosed(char *str, char c);
int		is_special(char **str, char **to_match);
t_ls	*path_is_valid(t_glob *g, char *path, char *name);
t_ls	*end_sort(t_glob *g, t_ls *tmp, char *str);
t_ls	*sort_files(t_glob *g, t_ls *begin, char *str);
t_ls	*sort_files2(t_glob *g, char *str);
t_ls	*recc(char *str, char **regex);
#endif
