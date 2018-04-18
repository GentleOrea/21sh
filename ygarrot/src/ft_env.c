/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:41:02 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/13 11:30:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_unsetenv(t_shell *sh, char *argv[])
{
	t_env *env;

	env = search_var(sh, sh->env_t, argv[0]);
	pop(env);
	env->value ? sh->env_size-- : 0;
	ft_memdel((void**)&env->value);
	ft_memdel((void**)&env->oldvalue);
	ft_memdel((void**)&env);
}

void		ft_setenv(t_shell *sh, char *argv[])
{
	t_env *env;

	env = search_var(sh, sh->env_t, argv[0]);
	env->value = ft_implode('=', argv[0], argv[1]);
	sh->env_size++;
}

static int	add(t_shell *sh, char *argv[])
{
	int		i;
	t_env	*end;
	char	*temp;

	i = -1;
	while (ft_isin('=', argv[++i]))
	{
		mallcheck(sh, temp = ft_strndup(argv[i], ft_charchr('=', argv[i])));
		end = search_var(sh, sh->env_t, temp);
		end->value ? end->oldvalue = end->value : 0;
		ft_memdel((void**)&temp);
		mallcheck(sh, end->value = ft_strdup(argv[i]));
		end->temp = 1;
		sh->env_size++;
	}
	sh->free += sh->free || i > 0;
	fill_env(sh);
	return (i);
}

void		ft_env(t_shell *sh, char *argv[])
{
	t_env	*temp;
	t_env	*to_del;
	int		i;

	i = add(sh, argv);
	if (argv[i])
		wait_exec(sh, &argv[i]);
	else if ((i = -1))
		while (sh->env[++i])
			ft_printf("%s\n", sh->env[i]);
	temp = sh->env_t;
	while (sh->free == 1 && temp)
	{
		to_del = temp;
		temp = temp->next;
		if (to_del->temp)
		{
			!to_del->oldvalue ? pop(to_del) : 0;
			ft_memdel((void**)&to_del->value);
			to_del->oldvalue ? to_del->value = to_del->oldvalue :
				ft_memdel((void**)&to_del);
			sh->env_size--;
		}
	}
	sh->free -= (sh->free) ? 1 : 0;
}
