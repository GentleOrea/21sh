/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/19 15:15:46 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(int ac, char **av, char **env)
{
	t_comm	*co = (t_comm*)ft_memalloc(sizeof(t_comm));
	(void)ac;(void)av;(void)env;
	
	hard_split(co, av[1]);
	split_co(co);
}
