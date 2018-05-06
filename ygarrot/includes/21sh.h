/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:17:19 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/04 19:55:57 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _21SH_H
# define _21SH_H
# include "../libft/includes/libft.h"
# include "../../tcharrie/includes/sh_define.h"
# include "../../tcharrie/includes/sh.h"
# include "glob.h"
# define UNESC "0xabfnrtv\\"
# define ESC "\a\b\f\n\r\t\v\\"

#define QUOTES "\"\'"
#define ALL (char *[13]){"||", "&&", "|", "&", ";", ">>", "<<",  "<<", ">&", "<&","<", ">" }
#define HD (char *[14]){"||", "&&", "|", "&", ";", ">>", "<<", ">&", "<&","<", ">" , " "}
#define SEP (char *[7]){"||", "&&", "|", "&", ";", "\n"}
#define M_SEP (char *[6])								{"||", "&&", "|"}
#define REDI (char *[7]){"<<", ">>", "<&",">&", "<", ">"}

#define BUILT (char *[6]){"echo", "cd", "env", "setenv", "unsetenv"}


typedef struct s_glob t_glob;

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

//Utilisée pour split les commandes et les redir
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

//Utilisée pour le parser
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

char	is_sep(char *str, t_parser *par, char **tb);
int		sizeof_comm(char *str, t_parser *par);
char	**split_cli(char *str, t_parser *par);
t_parser	*count_parser(char *str);
void	mallcheck(void *foo);
int		hard_split(t_shell *sh, char *str);
char	**ft_strsplit_comm(char *str, char *split);
int		skip_comm(char *str);
char	*ft_find_and_replace(char *str, char *rep, int op);
t_parser	*push_front(t_parser *com, char *str, int type);
t_parser	*easy_split(t_parser *c, char *str, char isamp);
int		search_op(char *str, char **op);
int		get_sep(char *str, char **tb);
void	split_co(t_shell *sh, t_parser *c);
int		redi(t_shell *sh, t_redi *redi);
char	*search_var(char **tb, char *str);
int		wait_exec(t_shell *sh, char **cli);
int		sort_comm(t_shell *sh, t_com *com);
void	epur_tb(t_com *inte, int len);
int		exec_pipe(t_shell *sh, char *comm, char **argv);
void		f_point(t_shell *sh);

int		ft_isbuiltin(char *path);
void	ft_builtin(char **arg, char ***env, int pid);
void	ft_echo(char **arg, char ***env);
void	ft_cd(char **arg, char ***env);
void	ft_setenv(char **arg, char ***env);
void	ft_unsetenv(char **arg, char ***env);
void	ft_env(char **arg, char ***env);
void	ft_exit(char **arg, char ***env);
int		ft_setenvvar(char **env, char *cur, char *var);
int		ft_strlento(char *str, char c);
char	**ft_strtbdup(char **tb);
void	ft_terminal_data(char **env);
int		exe(t_shell *sh, char *comm, char **argv);
int		search_exec(t_shell *sh, char *comm, char **argv);
char	*ft_getenv(char **tb, char *str);
int		exec_cli(t_shell *sh, t_com *inter);
int		exec_redi(t_shell *sh, t_redi *tmp);
void	ft_fatal(char *str);
t_com	*shift_com(t_com *com, int fail);

char	*conv_esc(char *str);
char	*set_esc(char *str);
int		error_exec(char **argv);
void	free_parser(t_parser *begin);
#endif
