/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:18:29 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/24 10:48:16 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include "ft_printf.h"
# define BUFFSIZE 30
# define BUILTIN "echo\0cd\0setenv\0unsetenv\0env\0exit\0"

typedef struct stat	t_stat;

int		ft_execute(char **line, char ***env);
char	**ft_convline(char *arg, char **env);
char	*ft_convline_gotonext(char *str);
char	*ft_convline_fill(char *arg, char **env);
int		ft_specialbl(char c);

char	*ft_getpath(char *arg, char **env);
char	*ft_getname(char *path);
char	**ft_convarg(char *arg);

int		ft_isbuiltin(char *path);
void	ft_builtin(char **arg, char ***env, int pid);
void	ft_echo(char **arg, char **env);
void	ft_cd(char **arg, char ***env);
void	ft_setenv(char **arg, char ***env);
void	ft_unsetenv(char **arg, char **env);
void	ft_env(char **arg, char **env);
void	ft_exit(char **arg, char **env);

char	*ft_getenv(char *name, char **env);
int		ft_setenvvar(char **env, char *cur, char *var);

t_list	*ft_var(void);
char	*ft_getvar(char *argname, char **env);
void	ft_setvar(char *line, char **env);
size_t	ft_sizevar(char *argname, char **env);
size_t	ft_sizenamevar(char *str);
char	*ft_var_extractname(char *str);

void	ft_cleanstrtab(char **tab);
#endif
