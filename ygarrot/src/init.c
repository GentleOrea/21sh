/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:13:21 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/13 12:26:19 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	classy(void)
{
	char	**color;
	char	*str;
	int		i;

	i = -1;
	str = "\
\tooo        ooooo  o8o               o8o           oooo              \
	oooo  oooo  \n\t `88.      .888'  `''               `''           `\
888                  `888  `888  \n\t 888b     d'888   oooo  ooo. .oo.  \
oooo   .oooo.o  888 .oo.    .ooooo.   888   888  \n\t 8 Y88. .P  888  `\
888  `888P'Y88b  `888  d88(  '8  888P'Y88b  d88' `88b  888   888  \n\t \
8  `888'   888   888   888   888   888  `'Y88b.   888   888  888ooo\
888  888   888  \n\t 8    Y     888   888   888   888   888  o.  )88b  \
888   888  888    .o  888   888  \n\to8o        o888o o888o o888o o888o\
o 888o 8''888P' o888o o888o `Y8bod8P' o888o o888o \n\0";
	color = (char *[8]){"{boldred}", "{boldmagenta}", "{boldblue}",
		"{boldcyan}", "{boldgreen}", "{boldyellow}", "{boldred}", ""};
	ft_printf("\n\n\n");
	while (str[++i])
	{
		if ((!i || str[i] == '\n') && *color + 1)
			ft_printf(*color++);
		write(0, &str[i], 1);
	}
	ft_printf("\n\n\n");
}

void	fill_env(t_shell *sh)
{
	t_env	*env;
	t_env	*to_del;
	int		i;

	i = 0;
	if (sh->env_size < 0)
		return ;
	env = sh->env_t;
	ft_memdel((void**)&sh->env);
	mallcheck(sh, sh->env =
			(char**)ft_memalloc((sh->env_size + 1) * sizeof(char*)));
	while (env)
	{
		env->value ? sh->env[i++] = env->value : 0;
		to_del = env;
		env = env->next;
		if (to_del && !to_del->value)
		{
			pop(to_del);
			ft_memdel((void**)&to_del);
		}
	}
}

void	init_built(t_shell *sh)
{
	char	**mybuilt;
	t_env	*pwd;
	t_env	*oldpwd;
	int		i;

	i = -1;
	mybuilt = (char *[6]){"echo", "cd", "env", "setenv", "unsetenv"};
	mallcheck(sh, sh->my_built = (char**)ft_memalloc(6 * sizeof(char*)));
	while (mybuilt[++i])
		mallcheck(sh, sh->my_built[i] = ft_strdup(mybuilt[i]));
	sh->f_built[0] = &ft_echo;
	sh->f_built[1] = &ft_cd;
	sh->f_built[2] = &ft_env;
	sh->f_built[3] = &ft_setenv;
	sh->f_built[4] = &ft_unsetenv;
	pwd = search_var(sh, sh->env_t, "PWD");
	oldpwd = search_var(sh, sh->env_t, "OLDPWD");
	sh->oldpwd = ft_strdup(&pwd->value[4]);
	sh->pwd = ft_strdup(sh->oldpwd);
}

void	init(t_shell *sh, char **env)
{
	t_env	*begin;
	int		del;
	int		i;

	classy();
	mallcheck(sh, begin = (t_env *)ft_memalloc(sizeof(t_env)));
	sh->env_t = begin;
	del = ft_charchr('=', env[0]);
	begin->value = ft_strdup(env[0]);
	i = 0;
	while (env[++i])
	{
		mallcheck(sh, begin->next = (t_env *)ft_memalloc(sizeof(t_env)));
		begin->next->prev = begin;
		begin = begin->next;
		del = ft_charchr('=', env[i]);
		begin->value = ft_strdup(env[i]);
	}
	sh->env_size = i;
	init_built(sh);
	fill_env(sh);
}

void	erase_shell(t_shell *sh)
{
	t_env	*to_del;

	ft_memdel((void**)&sh->env);
	ft_free_dblechar_tab(sh->my_built);
	while (sh->env_t)
	{
		to_del = sh->env_t;
		sh->env_t = sh->env_t->next;
		ft_memdel((void**)&to_del->value);
		ft_memdel((void**)&to_del);
	}
	ft_memdel((void**)&sh->oldpwd);
	ft_memdel((void**)&sh->pwd);
	ft_memdel((void**)&sh);
	ft_putchar('\n');
	exit(1);
}
