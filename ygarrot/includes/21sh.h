/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:17:19 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/20 18:49:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _21SH_H
# define _21SH_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <signal.h>

# define UNESC "abfnrtvc0x"
# define ESC "\a\b\f\n\r\t\v"

#define QUOTES "\"\'"
#define H_SEP ";&\n"

#define ALL (char *[13]){"||", "&&", "|", "&", ";", ">>", "<<",  "<<", ">&", "<", ">" }
#define HD (char *[14]){"||", "&&", "|", "&", ";", ">>", "<<", ">&", "<&","<", ">" , " "}
#define SEP (char *[6]){"||", "&&", "|", "&", ";"}
#define M_SEP (char *[6])								{"||", "&&", "|"}
#define REDI (char *[7]){">>", "<<", ">&","<&", "<", ">"}

#define BUILT (char *[6]){"echo", "cd", "env", "setenv", "unsetenv"}

typedef struct	s_tab
{
	char	*str;
	struct s_tab *next;
}				t_tab;


typedef struct	s_redi
{
	char	*path;
	int		type;
	int		n;
	struct s_redi *next;
}				t_redi;

//Utilisée pour split les commandes et les redir
typedef struct	s_inter
{
	char	**cli;
	int		len;
	int		type;
	t_tab	*tab;
	t_redi	*redi;
	struct s_inter	*next;
}				t_inter;

//Utilisée pour le parser
typedef struct s_comm
{
	char	*comm;
	char	op[3];
	char	type;
	struct	s_comm	*next;
}				t_comm;

typedef struct	s_env
{
	char			*value;
	char			*oldvalue;
	char			temp;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct	s_shell
{
	void	(*f_built[5])(char **av, char ***argv);
	char	**env;
	t_inter	com_t;
	char	*pwd;
}				t_shell;

char	is_sep(char *str, t_comm *par, char **tab);
int		sizeof_comm(char *str, t_comm *par);
char	**split_cli(char *str, t_comm *par);
void	count_comm(t_comm *par, char *str);
void	mallcheck(void *foo);
void	hard_split(t_comm *c, char *str);
char	**ft_strsplit_comm(char *str, char *split);
int		skip_comm(char *str);
char	*ft_find_and_replace(char *str, char *rep, int op);
t_comm	*push_front(t_comm *com, char *str);
t_comm	*easy_split(t_comm *c, char *str, char isamp);
int		search_op(char *str, char **op);
int		get_sep(char *str, char **tab);
void	split_co(t_shell *sh, t_comm *c);
int		redi(t_redi *redi);
char	*search_var(char **tab, char *str);
int		wait_exec(t_shell *sh, char **cli);
void	sort_comm(t_shell *sh, t_inter *com);

int		ft_isbuiltin(char *path);
void	ft_builtin(char **arg, char ***env, int pid);
void	ft_echo(char **arg, char ***env);
void	ft_cd(char **arg, char ***env);
void	ft_setenv(char **arg, char ***env);
void	ft_unsetenv(char **arg, char **env);
void	ft_env(char **arg, char **env);
void	ft_exit(char **arg, char **env);
int		ft_setenvvar(char **env, char *cur, char *var);
int		ft_strlento(char *str, char c);
char	**ft_strtabdup(char **tab);

void	exe(t_shell *sh, char *comm, char **argv);
int		search_exec(t_shell *sh, char *comm, char **argv);
char	*ft_getenv(char **tab, char *str);
int		exec_cli(t_shell *sh, t_inter *inter);
#endif
