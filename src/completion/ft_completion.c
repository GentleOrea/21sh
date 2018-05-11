/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:56:06 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 13:32:05 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_completion_type(t_line *line, int *val)
{
	if (val[4] == 0)
		return (COMPLETION_FILE);
	val[9] = ft_lenword_l(line->line, val[0]);
	if (val[9] - ft_lenword_l(line->line, val[0] - val[9]) > val[5])
		return (COMPLETION_FILE);
	return (1);
}
