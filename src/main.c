/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/08 17:49:20 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		main(int ac, char **av, char **env)
{
	t_shell sh;
	int		fd;
	t_line	line;

	(void)ac;(void)av;(void)env;
	f_point(&sh);
	ft_init_terminal_data(env);
	ft_initsig();
	if (ft_setattr() == -1)
		return (-1);
	sh.env = env;
	sh.fd = open("/dev/ttys003", O_RDWR);
	while (1)
	{
		fd = open("/dev/stdout", O_RDWR);
		line = ft_getentry();
		while (line.line == 0)
			line = ft_getentry();
		//if (ft_terminal_reset(0) == -1)
		//	ft_exit(0, 0);
		hard_split(&sh, &line);
		//if (ft_setattr() == -1)
		//	ft_exit(0, 0);
	}
}
