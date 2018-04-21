/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:54:38 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/21 15:50:45 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include "sh_define.h"
# include "../libft/libft.h"
# include "../include.h"
# include "minishell.h"

typedef struct termios	t_termios;

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

/*
** Fonction de gestion d'erreur et d'affichage divers et memoire
*/

void	ft_fatal(char *str);
char	*ft_conversion_error(int code);
char	*ft_init_aff(int *val);
int		writechar(int c);

void	ft_direction_del(void *content, size_t t);
void	ft_command_del(void *c, size_t t);

/*
** Parametrage du terminal
*/

void	ft_initenv(char ***env);

void	ft_init_terminal_data(char **env);
int		ft_setattr(void);

void	ft_initsig(void);
void	ft_sig_line(int sig);
int		ft_sigint(int pid);

/*
** Fonction d'historique
*/

t_list	**ft_history(void);
char	*ft_history_cache(char *str, int code);
int		ft_history_add(char *str);
char	*ft_history_get(int pos);

/*
** Recover user entry
*/

t_line	ft_getentry(void);
int		ft_read(t_line *line, int *ta);

int		ft_specialchar(t_line *line, char *str, int *val);
int		ft_specialchar_aux(t_line *line, char *str, int *val);

/*
** Move on the screnn
*/

int		ft_getpos(int *x, int *y);
int		ft_goto(int x, int y);

int		ft_move_left(t_line *line, int *val);
int		ft_move_right(t_line *line, int *val);
void	ft_move_up(t_line *line, int *val);
int		ft_move_down(t_line *line, int *val);
int		ft_move_tohome(t_line *line, int *val);
int		ft_move_toend(t_line *line, int *val);
int		ft_move_wordl(t_line *line, int *val);
int		ft_move_wordr(t_line *line, int *val);
int		ft_move_tolinel(t_line *line, int *val);
int		ft_move_toliner(t_line *line, int *val);
void	ft_move_tohist(t_line *line, int *val, int to);
void	ft_move_up_bis(char *str, int *val, int x, int y);
void	ft_move_up_ter(char *str, int *val, int y);
int		ft_move_down_bis(char *str, int *val, int x, int y);
int		ft_move_down_ter(char *str, int *val, int y);

int		ft_scroll_down(t_line *line, int *val);
int		ft_scroll_up(t_line *line, int *val);

int		ft_lenline_c(char *str, int pos);
int		ft_lenline_v(char *str, int pos);
int		ft_lenline_col(char *str, int pos, int col);
int		ft_lenchar_l(char *str, int pos);
int		ft_lenchar_r(char *str, int pos);
int		ft_lennchar_l(char *str, int pos, int n);
int		ft_lennchar_r(char *str, int pos, int n);
int		ft_lenword_l(char *str, int pos);
int		ft_lenword_r(char *str, int pos);

/*
** Fonction d'affichage
*/

int		ft_printchar(t_line *line, char *str, int *val);
int		ft_printinsert(t_line *line, int *val);
int		ft_printdec(char *str, int *val);
int		ft_lennline(char *str, int line, int col);

int		ft_realloc_line(t_line *line, int *val, int newsize);
int		ft_insert_noalloc(char *src, char *str, int size);

/*
**
*/

int		ft_erase(t_line *line, int *val);
int		ft_nerase(t_line *line, int *val, int n);
int		ft_delete(t_line *line, int *val);
int		ft_ndelete(t_line *line, int *val, int n);

/*
** Fonction de traitement de la ligne
*/

char	*ft_getline(void);

int		ft_bl_active(char *str, int pos);
int		ft_separator(char c, int sep, int bl);
int		ft_separator_active(char *str, int pos, int *bl, int *sep);

/*
** Builtins
*/

void	ft_cd(char **a, char ***env);
void	ft_echo(char **arg, char **env);
void	ft_env(char **arg, char **env);
void	ft_exit(char **arg, char **env);
void	ft_setenv(char **arg, char ***env);
void	ft_unsetenv(char **arg, char **env);

char	*ft_getenv(char *varname, char **env);

#endif
