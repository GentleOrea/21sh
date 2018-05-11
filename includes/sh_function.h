/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_function.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:12:50 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 13:36:45 by ygarrot          ###   ########.fr       */
/*   Updated: 2018/05/07 13:55:45 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_FUNCTION_H
# define SH_FUNCTION_H
# include "sh_include.h"
# include "sh_typedef.h"

/*
** Fonction de gestion d'erreur et d'affichage divers et memoire
*/

void	ft_fatal(char *str);
char	*ft_conversion_error(int code);
char	*ft_init_aff(int *val);
int		writechar(int c);

void	ft_direction_del(void *content, size_t t);
void	ft_command_del(void *c, size_t t);
void	ft_errorlog(char *str);

/*
** Parametrage du terminal
*/

int		ft_recoverenv(char ***env);
void	ft_initenv(char ***env);
void	ft_init_terminal_data(char **env);
int		ft_setattr(void);
int		ft_terminal_reset(t_termios *term);
void	ft_initsig(void);
void	ft_sig_line(int sig);

/*
** Fonction d'historique
*/

t_list	**ft_history(void);
char	*ft_history_cache(char *str, int code);
int		ft_history_add(char *str);
char	*ft_history_get(int pos);
int		ft_move_tohist(t_line *line, int *val, int dec);
char	*ft_history_parser(char *str);

int		ft_historyfile_open(void);

/*
** Recover user entry
*/

t_line	ft_getentry(void);
int		ft_read(t_line *line, int *ta);
int		ft_read_process(t_line *line, int *val, char *tmp, t_parser **pars);
int		ft_read_newline(t_line *line, int *val, t_parser **pars);
int		ft_read_newline_eof(t_line *line, int *val, t_parser **pars);
int		ft_heredoc_purge(char *str, int size);

int		ft_specialchar(t_line *line, char *str, int *val);
int		ft_specialchar_a(t_line *line, char *str, int *val);
int		ft_lentospecial(char *str);

/*
** Move on the screnn
*/

int		ft_getpos(int *x, int *y);
char	*ft_readtostr(char *str, char end, int fd, int tr);
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
int		ft_printnchar(t_line *line, char *str, int *val, int n);
int		ft_printstr(t_line *line, char *str, int *val);
int		ft_printinsert(t_line *line, int *val);
int		ft_printdec(char *str, int *val);
int		ft_getdown(void);
int		ft_lennline(char *str, int line, int col);

int		ft_realloc_line(t_line *line, int *val, int newsize);
int		ft_insert_noalloc(char *src, char *str, int size);

/*
** Fonction de suppression
*/

int		ft_erase(t_line *line, int *val);
int		ft_nerase(t_line *line, int *val, int n);
int		ft_delete(t_line *line, int *val);
int		ft_ndelete(t_line *line, int *val, int n);

int		ft_sigint(int pid);
int		ft_sigint_clear(t_line *line);

/*
** Fonction  de selection
*/

char	*ft_selected(char *str, int code);
int		ft_selected_moveleft(t_line *line, int *val);
int		ft_selected_moveright(t_line *line, int *val);
int		ft_selected_cpy(t_line *line, int *val);
int		ft_selected_paste(t_line *line, int *val);
int		ft_selected_reset(t_line *line, int *val);

/*
** Variable
*/

int			ft_variablecmp(void *left, void *right);
t_variable	ft_variable_create(char *name, void *data, int deep);


/*
** Fonction de traitement de la ligne
*/

char	*ft_getline(void);

int		ft_bl_active(char *str, int pos);
int		ft_separator(char c, int sep, int bl);
int		ft_separator_active(char *str, int pos, int *bl, int *sep);

/*
** ...
*/

char	is_sep(char *str, t_parser *par, char **tb);
int		sizeof_comm(char *str, t_parser *par);
char	**split_cli(char *str, t_parser *par);
t_parser	*count_parser(char *str);
void	mallcheck(void *foo);
int		hard_split(t_shell *sh, t_line *line);
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
void	ft_env(t_shell *sh, char **arg, char ***env);
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
int		ft_strlento_comm(char *str, char *to_find);
int		ft_match(char *str, char *to_match);
char	*enclosed(char *str, char c);
void	true_sort(t_paths *begin, t_paths *to_add);
int		is_special(char **str, char **to_match);
t_glob *ft_glob(char *regstr, int opt);
void	free_globs(t_glob *glob);
int		safe_dup(int fd1, int fd2, int *pipe);
void	arg_replace(t_shell *sh, char **arg);
int		write_env(char **env);
void	parse_exe(t_shell *sh, char *comm, char **arg);

t_paths	*path_is_valid(char *path, char *name, t_dirent *dire, char **regex);
t_paths	*end_sort(t_paths *tmp, char *str, char **regex);
t_paths	*files_queue(char *str, DIR *dir, char **regex);
t_paths	*recc(char *str, char **regex);
#endif
