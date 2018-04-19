/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:17:19 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/19 17:25:15 by ygarrot          ###   ########.fr       */
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

//						 256   128   64   32   16    8     4    2     1
#define ALL (char *[11]){"||", "&&", "|", "&", ";", ">>", "<<", "<", ">" }
#define HD (char *[11]){"||", "&&", "|", "&", ";", ">>", "<<", "<", ">" , " "}
#define SEP (char *[6]){"||", "&&", "|", "&", ";"}
#define M_SEP (char *[6])								{"||", "&&", "|"}
#define REDI (char *[7]){">>", "<<", ">&","<&", "<", ">"}

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
	int		size;
	char	**cli;
	t_tab	*tab;
	t_redi	*redi;
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
	void	(*f_built[5])(struct s_shell *sh, char *argv[]);
	char	**env;
	t_env	*env_t;
	int		env_size;
	char	*oldpwd;
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
void	split_co(t_comm *c);



/*
** minishell ygarrot
*/
void			init(t_shell *sh, char **env);
//void			mallcheck(t_shell *sh, void *to_check);
t_env			*search_var(t_shell *sh, t_env *list, char *to_find);
int				search_exec(t_shell *sh, char *comm, char *argv[]);
void			fill_env(t_shell *sh);
void			xe(t_shell *sh, char *comm, char **argv);
void			comm(t_shell *sh, char **comma);
void			signin_handler(int sig);
void			sigquit_handler(int sig);
void			tabchr(t_shell *sh, char *str, char is_old);
void			ft_echo(t_shell *sh, char *argv[]);
void			ft_cd(t_shell *sh, char *argv[]);
void			ft_env(t_shell *sh, char *argv[]);
void			ft_setenv(t_shell *sh, char *argv[]);
void			ft_unsetenv(t_shell *sh, char *argv[]);
void			sig_handler(int sign);
void			sig_run(t_shell *sh);
void			erase_shell(t_shell *sh);
void			wait_exec(t_shell *sh, char **ta);
void			exe(t_shell *sh, char *comm, char **argv);
#endif
