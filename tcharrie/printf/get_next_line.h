/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:47:04 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/13 09:08:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

typedef struct		s_getline
{
	char				*buf;
	int					fd;
	char				padding[4];
	struct s_getline	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
