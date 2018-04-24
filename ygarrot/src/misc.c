
char	*get_esc(char *str, int mal)
{
	int		lim;
	char	*ret;
	int		index;
	int		i;

	i = -1;
	lim = -1;
	if (!(ret = (char*)ft_memalloc(++mal * sizeof(char))))
		return (NULL);
	while (str[++i] && index != 7)
	{
		if (str[i] == '\\' &&
				(index = ft_charchr(str[i + 1], UNESC)) > 0 && ++i)
		{
			ret[++lim] = index < 7 ? ESC[index] :
				ft_atoi_base(&str[i + 1], (index - 7) * 8);
			if (index > 7)
				i += ft_occiter(&str[i + 1], (index - 7) * 8, ft_isbase);
		}
		else
			ret[++lim] = str[i];
	}
	return (ret);
}
