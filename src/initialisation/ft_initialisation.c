/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:51:54 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/26 13:38:37 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_initialisation(char **env, t_shell *sh)
{
	char	***check;

	ft_init_terminal_data(env);
	ft_initsig();
	if (ft_setattr() == -1)
		ft_fatal("Can't set terminal's attributes");
	if (!(check = ft_storeenv(env)))
		ft_fatal("A fatal error occured");
	if (!*check)
		ft_fatal("A fatal error occured");
	if (!(sh->env = *check))
		ft_fatal("Can't malloc the env");
}
