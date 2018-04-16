/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:30:38 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/16 14:28:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

#define QUOTES "\"\'"
#define DEL ";&\n"
#define HERE ";|\n"

#define SEP (char *[6]){"||", "&&", "|", "&", ";"}
#define REDI (char *[6]){">>", "<<", "<", ">"}

char		is_sep(char *str, t_parser *glob)
{
	int		i;
	char	len;

	i = -1;
	while (++i < 5 && !ft_strnstr(str, SEP[i],len = ft_strlen(SEP[i])))
		;
	//ft_printf("%d\n", i);
	i < 5 ? ft_strcpy(glob->sep, SEP[i]) : 0;
	return ((i < 5) ? len : 0);
}

int		sizeof_comm(char *str, t_parser *glob)
{
	int		i;
	char	temp;
	char	q;

	i = 0;
	temp = 0;
	while (str[i] && !(temp = is_sep(&str[i], glob)))
	{
		if (ft_isin(str[++i], QUOTES) && (q = str[i] == '"' ? '"' : '\''))
			while (str[i] && str[++i] != q)
				;
	}
	if (str[i] == ';' || ft_strnstr(&str[i], ";;", 2))
		return (!ft_strnstr(&str[i], ";;", 2) ? 1 : -1);
	ft_printf("sizeof : [%d][%d]%s\n", i,temp, str);
	return (i || !str[i] ? i + temp : -1);
}


int		count_comm(t_parser *glob, char *str)
{
	int		i;
	int		mal;
	int		temp;

	mal = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		temp = sizeof_comm(&str[i], glob);
		if (temp < 0)
			return (-ft_printf("yosh: parse error near %s", glob->sep));
		i += temp;
		mal++;
	}
	return (mal);
}

char	**split_cli(char *str, int mal)
{
	int	i;
	char	**ret;

	if (!(ret = (char**)ft_memalloc(mal * sizeof(char*))))
		return (NULL);
	mal = 1;
	i = 0;
	while (str[i])
	{
		if (!(ret[i] = (char*)ft_memalloc(sizeof(char))))
			return (NULL);
	}
	return (ret);
}


int main(int ac, char **av)
{
	t_parser	glob;
	(void)ac, (void)av;
	
	ft_printf("%d\n", count_comm(&glob, av[1]));
}
