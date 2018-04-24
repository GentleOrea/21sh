/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:33:35 by tcharrie          #+#    #+#             */
/*   Updated: 2018/03/03 12:05:15 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

int	main(int ac, char **av, char **env)
{
	(void)av;
	ft_initsig();
	if (!(env = ft_strtabdup(env)))
		ft_fatal("Failed to dup the env");
	ft_initenv(&env);
	ft_init_terminal_data(env);
	ac = ft_setattr() < 1;
	while (1)
	{
		write(1, "$>", 2);
		if ((av = ft_getline()))

	}
}
