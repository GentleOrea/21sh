/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:52:17 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/13 12:24:11 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pop(t_env *env)
{
	env->prev ? env->prev->next = env->next : 0;
	env->next ? env->next->prev = env->prev : 0;
}

t_env	*search_var(t_shell *sh, t_env *list, char *to_find)
{
	if (!list || !to_find || !sh)
		return (NULL);
	if (!list->value ||
			ft_strnstr(list->value, to_find, ft_strlen(list->value)))
		return (list);
	if (list->next &&
			!ft_strnstr(list->value, to_find, ft_strlen(list->value)))
		return (search_var(sh, list->next, to_find));
	mallcheck(sh, list->next = (t_env*)ft_memalloc(sizeof(t_env)));
	list->next->prev = list;
	return (list->next);
}
