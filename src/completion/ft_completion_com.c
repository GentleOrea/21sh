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

char	*ft_completion_com(char *left, int loc, int bl, int sep)
{
	char		*right;
	t_dirent	*file;
	DIR			*dir;
	size_t		i[3];
	char		*path;

	if (!left)
		return (0);
	if (!(path = ft_getenv(path)))
		return (0);
	i[0] = ft_strlen(left);
	i[1] = 0;
	while (loc > 0 && path[i[1]])
	{
		i[2] = ft_strlento(


	}
	return(0);
}
