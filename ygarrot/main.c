/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/25 11:10:23 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(int ac, char **av, char **env)
{
	t_shell sh;

	//ft_terminal_data(env);
	(void)ac;(void)av;(void)env;
	sh.env = env;
	hard_split(&sh, av[1]);
}
