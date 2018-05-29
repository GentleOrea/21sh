/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variablepars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:17:26 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/29 13:04:21 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_variablepars_bracket(char *str)
{
	t_variable	*var;
	size_t		i;
	char		*tmp;

	if (!str || *str != '$' || str[1] != '{')
		return (0);
	i = 2;
	while (str[i] && !ft_isin(VAR_LIM, str[i]))
		i += ft_lenchar_r(str[i]);
	if (str[i] != '}')
		return (0);
	str[i] = 0;
	var = ft_variableget(&str[2]);
	str[i] = '{';
	if (!var)
		return ((char*)ft_memalloc(1));
	tmp = ft_variablestr(var);
	return (tmp);
}

char	*ft_variablepars(char *str)
{
	t_variable	*var;
	size_t		i;
	char		c;
	char		*tmp;

	if (!str || *str != '$')
		return (0);
	if (str[1] == '{')
		return (ft_variablepars_bracket(str));
	i = 1;
	while (str[i] && !ft_isin(VAR_LIM, str[i]))
		i += ft_lenchar_r(str, i);
	c = str[i];
	str[i] = 0;
	var = ft_variableget(&str[1]);
	str[i] = c;
	if (!var)
		return ((char*)ft_memalloc(1));
	tmp = ft_variablestr(var);
	return (tmp);
}

size_t	ft_variablelen(t_variable *var)
{
	int			i;
	size_t		len;

	if (!var || var->deep < 1 || var->deep > 2)
		return (0);
	if (var->deep == 1)
		return (ft_strlen(var->str));
	if (!(var->array))
		return (0);
	i = 0;
	len = 0;
	while (var->array[i])
		len += ft_strlen(var->array[i]) + 1;
	if (i > 0)
		len -= 1;
	return (len);
}

char	*ft_variablestr(t_variable *var)
{
	char	*value;
	size_t	len;
	int		i;

	if (!var || var->deep < 1 || var->deep > 2)
		return (0);
	if (var->deep == 1)
		return (ft_strdup(var->name));
	if (!(len = ft_variablelen(var)))
		return (ft_strdup(" "));
	if (!(value = (char*)malloc(len)))
		return (0);
	value[0] = 0;
	len = 0;
	i = 0;
	while (var->array[i])
	{
		ft_strcat(&value[len], var->array[i]);
		len += ft_strlen(&value[len]);
		i++;
		if (var->array[i])
			value[len++] = ' ';
	}
	return (value);
}
