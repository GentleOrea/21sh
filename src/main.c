/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/12 13:06:10 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		main(int ac, char **av, char **env)
{
	t_shell sh;
	t_line	line;

	(void)ac;
	(void)av;
	f_point(&sh);
	ft_init_terminal_data(env);
	ft_initsig();
	if (ft_setattr() == -1)
		return (-1);
	sh.env = ft_strtbdup(env);
	if (ft_envwrite(ft_getenvfile(CODE_ENVGET), sh.env) == -1)
		ft_fatal("Failed to copy env\n");
	sh.fd = open("/dev/ttys004", O_RDWR);
	while (1)
	{
		line = ft_getentry();
		while (line.line == 0)
			line = ft_getentry();
		hard_split(&sh, &line);
		ft_memdel((void**)&line.line);
	}
}
