/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_typedef.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:04:19 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/08 15:23:19 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TYPEDEF_H
# define SH_TYPEDEF_H
# include "sh_include.h"

typedef struct termios	t_termios;
typedef struct dirent	t_dirent;
typedef struct s_glob	t_glob;

typedef struct	s_variable
{
	int		deep;
	char	*name;
	char	*str;
	char	**array;
}				t_variable;

typedef struct	s_line
{
	char	*eof;
	int		size_eof;
	char	*line;
	int		size_line;
}				t_line;

typedef struct	s_direction
{
	int		in;
	char	*out_file;
	char	*in_string;
	int		out_fd;
	int		out_type;
}				t_direction;

typedef struct	s_command
{
	t_list	*direction;
	char	*line;
	int		separator;
}				t_command;

typedef struct	s_corr
{
	int	x;
	int	y;
}				t_corr;

typedef struct	s_tb
{
	t_glob	*glob;
	char	*str;
	struct s_tb *next;
}				t_tb;

typedef struct	s_redi
{
	char	*path;
	int		type;
	int		fd[2];
	struct s_redi *next;
}				t_redi;

typedef struct	s_com
{
	char	**cli;
	int		pipe[2];
	int		len;
	int		type;
	t_tb	*tb;
	t_redi	*redi;
	struct s_com	*next;
}				t_com;

typedef struct s_parser
{
	char	*comm;
	char	op[3];
	char	type;
	int		wait;
	struct	s_parser	*next;
}				t_parser;

typedef struct	s_shell
{
	void	(*f_built[5])(char **av, char ***argv);
	int		fd;
	char	*here_doc;
	char	**env;
	t_com	*com;
	t_com	*tmp;
	pid_t	test;
	char	*pwd;
}				t_shell;

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

#endif
