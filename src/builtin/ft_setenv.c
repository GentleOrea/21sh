/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:56:40 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/26 13:52:40 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void		ft_setenv(char **arg, char ***env)
{
	char	**cpy;

	if (!arg || !env || !*env)
		write(STDOUT_FILENO, "\n", 1);
	else if (!*arg || !arg[1])
		ft_putendl_fd("21sh: setenv VARNAME [VARVALUE]", 2);
	else
	{
		if (!(cpy = ft_strtbdup(*env)))
		{
			ft_errorlog("Failed to insert an element in the env");
			ft_putstr_fd("Failed to insert an element in the env\n", 2);
		}
		ft_storeenv(cpy);
	}
}
