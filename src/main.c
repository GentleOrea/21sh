/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/17 13:30:32 by ygarrot          ###   ########.fr       */
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
	ft_initialisation(env, &sh);
	sh.fd = open("/dev/ttys006", O_RDWR);
	while (1)
	{
		line = ft_getentry();
		while (line.line == 0)
			line = ft_getentry();
		hard_split(&sh, &line);
		ft_delline(&line);
	}
	erase_shell(&sh);
}
