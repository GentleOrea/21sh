/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:21:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/11 13:26:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_getenv(char **tb, char *str)
{
	int	i;
	int	len;

	i = 0;
	if (!tb || !str)
		return (NULL);
	len = ft_strlen(str);
	while (*tb && ft_strncmp(*tb, str, len))
		tb++;
	return (*tb);
}
