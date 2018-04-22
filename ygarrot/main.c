/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/21 13:15:00 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(int ac, char **av, char **env)
{
	t_parser	*co = (t_parser*)ft_memalloc(sizeof(t_parser));
	t_shell sh;
	(void)ac;(void)av;(void)env;
	sh.env = env;
	hard_split(co, av[1]);
	split_co(&sh, co);
}
