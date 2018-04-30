/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globbing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:42 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/30 18:56:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLOB "[*?"
#include "21sh.h"

int ft_strlento_comm(char *str, char *to_find)
{
	int i;

	i = 0;
	if (!str || !to_find)
		return (-1);
	while (str[i])
	{
		i += skip_comm(&str[i]);
		if (ft_isin(str[i++], to_find))
			return (i);
	}
	return (0);
}

int		brace(char **str, char **match)
{
	int		i;
	int		len;
	int		temp;

	i = 1;
	if (**match != '{')
		return (0);
	len = ft_strlento_comm(*match, "}");
	while (match[0][i - 1] != '}')
	{
		temp = ft_strlento_comm(&match[0][i], ",}");
		if (!ft_strncmp(*str, &match[0][i], temp - 1))
		{
			*str += temp - 1;
			*match += len;
			return (1);
		}
		i += temp ;
	}
	return (0);
}

char	*enclosed(char *str, char c)
{
	int			i;
	int			len;


	if (!str || !ft_isin(*str, "[?"))
		return (NULL);
	if (*str == '?')
		return (str + 1);
	str++;
	i = 0;
	len = ft_strlento_comm(str, "]");
	while (i - len)
	{
		if (str[i] == '\\')
			i++;
		if (len - i + 2 >= 0 && str[i + 1] == '-')
		{
			if (c >= str[i] && c <= str[i + 2])
				return (&str[len]);
			i += 2;
		}
		if (c == str[i++])
			return (&str[len]);
	}
	return (NULL);
}

int		is_special(char **str, char **to_match)
{
	char	*temp;
	int		i;

	i = 0;
	if (**to_match == '{')
		return (brace(str, to_match));
	if ((temp = enclosed(*to_match, **str)))
	{
		*to_match = temp;
		++*str;
	}
	if (temp || **to_match == '[')
		return (temp ? 1 : 0);
	while (to_match[0][i] && !ft_isin(to_match[0][i], GLOB) && to_match[0][i] == str[0][i])
		i++;
	if ((to_match[0][i] && !ft_isin(to_match[0][i], GLOB)) || (!to_match[0][i] && str[0][i]))
		return (0);
	*to_match = &to_match[0][i];
	*str = &str[0][i];
	return (i | 1);
}

int ft_match(char *str, char *to_match)
{
	int	len;

	if (!to_match || !str)
		return (0);
	if (!*str && !*to_match)
		return (1);
	else if (!*str)
		return (*to_match == '*' ? ft_match(str, to_match + 1) : 0);
	if (*to_match == '*')
	{
		if (ft_match(str, to_match + 1))
			return (1);
		return (ft_match(str + 1, to_match));
	}
	else if (is_special(&str, &to_match))
		return (ft_match(str, to_match));
	return (0);
}
