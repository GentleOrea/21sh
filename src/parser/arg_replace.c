/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:41:24 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/13 16:02:57 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	arg_replace(t_shell *sh, char **arg)
{
	char	*temp[3];
	char	*todel;
	int		i;
	int		len;

	i = -1;
	while ((*arg)[++i] && (i += skip_comm(&(*arg)[i])) && (*arg)[i])
		if ((*arg)[i] == '$'
				|| ((*arg)[i] == '~' && (!i || (*arg)[i - 1] == ' ')))
		{
			temp[0] = (*arg)[i] == '$' ? &(*arg)[i + 1] : "HOME";
			len = ft_mcharchr(temp[0], " /*{\'\"");
			len = len >= 0 ? len : ft_strlen(temp[0]);
			todel = ft_strndup(temp[0], len);
			if (!(temp[1] = ft_getenv(sh->env, todel)))
				return ;
			ft_memdel((void**)&todel);
			todel = ft_strndup(*arg, i);
			temp[2] = *arg;
			*arg = ft_implode(&temp[1][len + 1], todel
			, &(*arg)[i + 1 + ((*arg)[i] == '$' ? len : 0)]);
			ft_memdel((void**)&temp[2]);
			ft_memdel((void**)&todel);
		}
}
