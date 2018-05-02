/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:24:42 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/01 14:20:48 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H
# include "21sh.h"
# define GLOB "[*?"

typedef struct dirent t_dirent;
typedef struct s_glob t_glob;

typedef struct	s_paths
{
	char			is_dir;
	char			*path;
	char			*name;
	struct s_paths	*next;
}				t_paths;

struct	s_glob
{
	int				nb_paths;
	t_paths			*paths;
};

int		ft_strlento_comm(char *str, char *to_find);
int		ft_match(char *str, char *to_match);
char	*enclosed(char *str, char c);
int		is_special(char **str, char **to_match);
t_glob *ft_glob(char *regstr, int opt);
void	free_globs(t_glob *glob);

t_paths	*path_is_valid(char *path, char *name, t_dirent *dire, char **regex);
t_paths	*end_sort(t_paths *tmp, char *str, char **regex);
t_paths	*files_queue(char *str, DIR *dir, char **regex);
t_paths	*recc(char *str, char **regex);


#endif
