/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:56:40 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 13:47:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static void	ft_setenvnew_aux(char ***env, char **tb, char *str)
{
	int	i;

	i = -1;
	while (env[0][++i])
		tb[i] = (*env)[i];
	tb[i++] = str;
	tb[i] = 0;
	free(*env);
	*env = tb;
}

static void	ft_setenvnew(char ***env, char *var, char *value)
{
	int		i;
	char	*str;
	char	**tb;

	i = 0;
	while ((*env)[i])
		i++;
	if (!(tb = (char**)malloc(sizeof(char*) * (i + 2))))
		return ;
	str = ft_implode(var, "=", value);
	ft_setenvnew_aux(env, tb, str);
}

static void	ft_setenvaux(char **a, char **env)
{
	char *tmp;

	tmp = ft_implode(a[1], "=", a[2]);
	ft_memdel((void**)*env);
	*env = tmp;
}

void		ft_setenv(char **arg, char ***env)
{
	int		i;
	size_t	j;

	i = 0;
	if (!arg || !env || !*env)
		ft_printf("\n");
	else if (!arg[1])
		ft_putendl_fd("minishell: setenv VARNAME [VARVALUE]", 2);
	else
	{
		j = ft_strlen(arg[1]);
		while ((*env)[i] && (ft_strncmp(arg[1], (*env)[i], j) ||
				(*env)[i][j] != '='))
			i++;
		if ((*env)[i] && !arg[2])
			(*env)[i][ft_strlento((*env)[i], '=') + 1] = 0;
		else if ((*env)[i] && arg[2])
			ft_setenvaux(arg, &(*env)[i]);
		else
			ft_setenvnew(env, arg[1], arg[2]);
	}
	write_env(*env);
}
