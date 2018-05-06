#include "sh.h"

char	*ft_addmemory(char **str, int size, int add)
{
	char	*val;

	if (!str || add < 0 || size + add <= 0)
		return (0);
	if (!(val = (char*)malloc(size + add)))
	{
		ft_strdel(str);
		return (0);
	}
	ft_memcpy((void*)val, (void*)*str, (size_t)(size + add));
	while (add-- > 0)
		val[size++] = 0;
	free(*str);
	*str = val;
	return (val);
}

char	*ft_readtostr_a(char *buff, int fd, int over)
{
	char	*tmp;

	tmp = over >= 0 ? ft_strdupto(&buff[over], ';') : 0;
	if (over >= 0)
		ft_addtofd(buff[over + 1 + ft_strlento(&buff[over], '\n')], fd);
	if (over >= 0)
		buff[over] = 0;
	ft_addtofd(buff, fd);
	free(buff);
	return (tmp);
}

char	*ft_readtostr(char *str, int fd, int try)
{
	char	*buff;
	int		re;
	int		over;
	int		size;

	over = -1;
	re = 0;
	size = 100;
	if (!(buff = (char*)ft_memalloc(size)))
		return (-1);
	while (try-- > 0 && re < 5 && over == -1)
	{
		re += read(fd, &buff[re], size - re);
		if ((over = ft_strinstr(buff, str)) == -1 && re == size)
		{
			if (!ft_addmemory(&buff, size, 100))
				return (-1);
			size += 100;
		}
	}
	return (ft_readtostr_a(buff, fd, over));
}
