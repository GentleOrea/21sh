/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion_com.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:51:09 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/17 15:55:20 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_completion_com_(char *left, int *loc, DIR *dir, char **right)
{
	size_t		i;
	t_dirent	*file

	if (!dir || !left || !loc || !right)
		return ;
	i = ft_strlen(left);
	while (*loc > 0 && (file = readdir(dir)))
	{
		if (!ft_strncmp(left, file->name, i))
			*loc--;
		if (*loc == 0 && ft_strlen(file->name) > i)
			*right = ft_strdup(&(file->name)[i]);
		else if (*loc == 0)
			*right = ft_strdup(" ");
	}
}

char	*ft_completion_com(char *left, int loc, int bl, int sep)
{
	char		*right;
	DIR			*dir;
	size_t		i[2];
	char		*path;

	if (!left)
		return (0);
	if (!(path = ft_getenv(path)))
		return (0);
	i[0] = 0;
	right = 0;
	while (loc > 0 && path[i[0]])
	{
		i[1] = i[0] + ft_strlento(&path[i[0]], ':');
		if (path[i[1]])
			path[i[1]] = 0;
		if (path[i[1]])
			i[1]++;
		if ((dir = opendir(&path[i[0]])))
			ft_completion_com_(left, &loc, dir, &right);
		i[0] = i[1];
	}
	path = ft_straddsep(right, bl, sep);
	ft_strdel(&right);
	return(path);
	}
