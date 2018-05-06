/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:02:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/06 12:01:37 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(int ac, char **av, char **env)
{
	t_shell sh;
	char	*str;

	(void)ac;(void)av;(void)env;
	f_point(&sh);
	ft_terminal_data(env);
	sh.env = env;
	sh.fd = open("/dev/ttys003", O_RDWR);
	while (1)
	{
		ft_printf("$>");
		int fd;
		if ((fd = open("/dev/stdout", O_RDWR)) <= 0)
			ft_printf("error open\n");
		if (get_next_line(fd, &str) <= 0)
		{perror("main");
			return (0);}
		hard_split(&sh, str);
		ft_memdel((void**)&str);
	}
}
