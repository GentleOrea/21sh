/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:17:19 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/24 11:58:04 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _21SH_H
# define _21SH_H
//# include "../libft/includes/libft.h"
# include <stdio.h>
# include <signal.h>
# include "sh.h"

# define UNESC "abfnrtvc0x"
# define ESC "\a\b\f\n\r\t\v"

#define QUOTES "\"\'"
#define H_SEP ";&\n"

#define ALL (char *[13]){"||", "&&", "|", "&", ";", ">>", "<<",  "<<", ">&", "<&","<", ">" }
#define HD (char *[14]){"||", "&&", "|", "&", ";", ">>", "<<", ">&", "<&","<", ">" , " "}
#define SEP (char *[7]){"||", "&&", "|", "&", ";", "\n"}
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
	t_tab	*ta;
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
	char	**env;
	t_com	*com;
	t_com	*tmp;
	char	*pwd;
}				t_shell;

char	is_sep(char *str, t_parser *par, char **t);
int		sizeof_comm(char *str, t_parser *par);
char	**split_cli(char *str, t_parser *par);
t_parser	*count_parser(char *str);
void	mallcheck(void *foo);
//void	hard_split(t_line line);
char	**ft_strsplit_comm(char *str, char *split);
int		skip_comm(char *str);
char	*ft_find_and_replace(char *str, char *rep, int op);
t_parser	*push_front(t_parser *com, char *str, int type);
t_parser	*easy_split(t_parser *c, char *str, char isamp);
int		search_op(char *str, char **op);
int		get_sep(char *str, char **t);
void	split_co(t_shell *sh, t_parser *c);
int		redi(t_redi *redi);
char	*search_var(char **t, char *str);
int		wait_exec(t_shell *sh, char **cli);
int		sort_comm(t_shell *sh, t_com *com);
void	epur_tab(t_com *inte, int len);
void	exec_pipe(t_shell *sh, char *comm, char **argv);

char	**ft_strtabdup(char **t);

int		exe(t_shell *sh, char *comm, char **argv);
int		search_exec(t_shell *sh, char *comm, char **argv);
char	*ft_getenv(char **t, char *str);
int		exec_cli(t_shell *sh, t_com *inter);
int		exec_redi(t_redi *tmp);
#endif
