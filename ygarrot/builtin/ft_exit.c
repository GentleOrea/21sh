/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:58:27 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/20 16:56:27 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_exit(char **arg, char **env)
{
//	t_list	*lst;

	//lst = ft_var();
	//ft_lstdel(&lst, &ft_lstfree);
	(void)arg;
	(void)env;
	exit(0);
}
