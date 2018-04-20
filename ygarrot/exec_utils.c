/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:21:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/20 18:45:45 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	*ft_getenv(char **tab, char *str)
{
	int	i;
	int	len;

	i = 0;
	if (!tab || !str)
		return (NULL);
	len = ft_strlen(str);
	while (*tab && ft_strncmp(*tab, str, ft_strlen(str)))
		tab++;
	return (*tab);
}
