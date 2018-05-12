/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:42:56 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/12 17:13:44 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_getdir(char *str)
{
	char	*directory;
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!(j = 0) && str && (*str == '/' || *str == '~'))
	{
		i = ft_strlen(str);
		while (i >= 0 && str[i] != '/')
			i--;
		return (ft_strndup(str, i));
	}
	if (!(tmp = getcwd(0, 0)))
		return (0);
	if (!(directory = (char*)malloc(ft_strlen(tmp) + ft_strlen(str) + 1)))
		ft_strdel(&tmp);
	if (!directory || (i = 0))
		return (0);
	while (tmp[i])
		directory[j++] = tmp[i++];
	i = 0;
	while (str && str[i])
		directory[j++] = str[i++];
	directory[j] = 0;
	return (directory);
}

char	*ft_completion_getfilename(char *begin)
{
	char	*file;
	int		i;
	char	*directory;
	DIR		*dir;

	i = 0;
	if (!(directory = ft_completion_save(CODE_GET, 0)))
	{
		directory = ft_getdir(begin);
		ft_completion_save(CODE_SET, directory);
		ft_completion_count(CODE_RESET);
	}
	ft_strdel(&begin);
	if (!directory)
		return (0);
	
	return (str);
}
