#include "get_next_line.h"

static char	*merge(char *dest, char *tab)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (dest)
		i = ft_strlen(dest);
	if (tab)
		j = ft_strlen(tab);
	str = (char *)malloc(sizeof(*str) * (i + j + 1));
	ft_memcpy(str, dest, i);
	ft_memcpy(str + i, tab, j);
	str[i + j] = '\0';
	free(dest);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (str);
}

static int	check(char **dest, char **tab, char **line, int fd)
{
	char	*ptr;
	int		end;

	end = 0;
	dest[fd] = merge(dest[fd], *tab);
	ptr = dest[fd];
	while (ptr[end] != '\n' && ptr[end])
		end++;
	if (ptr[end] == '\n')
		dest[fd][end] = '\0';
	else
		end = -1;
	if (end > -1)
	{
		*line = ft_strdup(dest[fd]);
		ptr = dest[fd];
		dest[fd] = ft_strdup(dest[fd] + end + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char *dest[66666];
	char		*buf;
	int			result;
	int			ret;

	buf = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, buf, 0)) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		result = check(dest, &buf, line, fd);
		free(buf);
		if (result == 1)
			return (1);
		buf = ft_strnew(BUFF_SIZE);
	}
	if ((result = check(dest, &buf, line, fd)))
		return (1);
	else if (ft_strlen(dest[fd]) > 0)
	{
		*line = ft_strdup(dest[fd]);
		ft_strdel(&dest[fd]);
		return (1);
	}
	return (result);
}