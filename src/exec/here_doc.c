/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:40:47 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/10 11:08:39 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void here_doc(t_shell *sh, t_redi *redi)
{
	mallcheck(redi->path = (char*)ft_memalloc(18 * (sizeof(char))));
	ft_strcpy(redi->path,"/tmp/.sh_heredoc");
	redi->path[11] = redi->fd[0] + '0';
}
