/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:22:10 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/17 18:47:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <signal.h>

# define UNESC "abfnrtvc0x"
# define ESC "\a\b\f\n\r\t\v"

#define QUOTES "\"\'"
#define H_SEP ";&\n"

//						 256   128   64   32   16    8     4    2     1
#define ALL (char *[11]){"||", "&&", "|", "&", ";", ">>", "<<", "<", ">" }
#define SEP (char *[6]){"||", "&&", "|", "&", ";"}
#define M_SEP (char *[6]){"||", "&&", "|"}
#define REDI (char *[5]){">>", "<<", "<", ">"}

typedef struct s_parser
{
	char	*str;
	char	sep[3];
	int		doc_h;
	int		nco;
	bool	split;
	char	*del;
}				t_parser;

typedef struct	s_env
{
	char			*value;
	char			*oldvalue;
	char			temp;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_comm
{
	char	*comm;
	char	type;
	struct	s_comm	*ou;
	struct	s_comm	*et;
	struct	s_comm	*prev;
	struct	s_comm	*next;
}				t_comm;

typedef struct	s_shell
{
	void	(*f_built[5])(struct s_shell *sh, char *argv[]);
	char	**env;
	t_env	*env_t;
	int		env_size;
	char	*oldpwd;
	char	*pwd;
}				t_shell;




char	is_sep(char *str, t_parser *par, char **tab);
int		sizeof_comm(char *str, t_parser *par);
char	**split_cli(char *str, t_parser *par);
int		count_comm(t_parser *par, char *str);
void	mallcheck(void *foo);
void	hard_split(t_comm *c, char *str);
char	**ft_strsplit_comm(char *str, char *split);
int		skip_comm(char *str);
char	*ft_find_and_replace(char *str, char *rep, int op);
t_comm	*push_front(t_comm *com, char *str);







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
void			pop(t_env *env);
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
