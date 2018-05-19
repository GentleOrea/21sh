/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:42:56 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/17 15:16:29 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_getdir(char *str)
{
	char	*directory;
	char	*tmp;
	size_t	i;

	if (!str)
		return (0);
	if (str && *str == '/' && (i = ft_strlen(str)))
	{
		while (i >= 0 && str[i] != '/')
			i--;
		return (ft_strndup(str, i));
	}
	tmp = 0;
	if (*str != '~' && !(tmp = getcwd(0, 0)))
		return (0);
	if (!(directory = (char*)ft_memalloc(ft_strlen(str) + 1 +
		((*str == '~') ? (ft_strlen(ft_getenv(HOME))) : (ft_strlen(tmp))))))
		ft_strdel(&tmp);
	if (!directory)
		return (0);
	ft_strcat(directory, (*str == '~') ? ft_getenv(HOME) : (tmp));
	ft_strcat(directory, (*str == '~')  ? (&str[1]) : (str));
	return (directory);
}

char	*ft_completion_getfilename(char *left, int loc, int bl, int sep)
{
	char		*right;
	size_t		i;
	DIR			*dir;
	t_dirent	*file;

	if (loc <= 0)
		return (0);
	if (!(dir = ft_opendirfree(ft_getdir(left))))
		return (0);
	i =  ft_strlen(left);
	right = 0;
	while (loc > 0 && (file = readdir(dir)))
	{
		if (!ft_strncmp(left, dir->name, i))
			loc--;
		if (loc == 0 && ft_strlen(dir->name) != i)
			right = &(dir->name)[i];
		else if (loc == 0)
		{
			closedir(dir);
			return (ft_strdup(" "));
		}
	}
	closedir(dir);
	return (ft_straddsep(right, bl, sep));
}
