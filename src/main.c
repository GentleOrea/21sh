/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/06 14:19:36 by ygarrot          ###   ########.fr       */
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
	if (ft_setattr() == -1)
		return (-1);
	sh.env = env;
	sh.fd = open("/dev/ttys003", O_RDWR);
	while (1)
	{
		if ((fd = open("/dev/stdout", O_RDWR)) <= 0)
			ft_printf("error open\n");
		line = ft_getentry();
		while (line.line == 0)
			line = ft_getentry();
		ft_printf("%s\n", line.line);
		hard_split(&sh, line.line);
	}
}
