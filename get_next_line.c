/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:30:05 by kbelov            #+#    #+#             */
/*   Updated: 2019/03/23 18:02:53 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_putline(char **files, char **lines, int fd, int bytes_read)
{
	char			*tmp_line;
	long			len;

	len = 0;
	while (files[fd][len] != '\n' && files[fd][len] != '\0')
		len++;
	if (files[fd][len] == '\n')
	{
		*lines = ft_strsub(files[fd], 0, len);
		tmp_line = ft_strdup(files[fd] + len + 1);
		free(files[fd]);
		files[fd] = tmp_line;
		if (files[fd][0] == '\0')
			ft_strdel(&files[fd]);
	}
	else if (files[fd][len] == '\0')
	{
		if (bytes_read == BUFF_SIZE)
			return (get_next_line(fd, lines));
		*lines = ft_strdup(files[fd]);
		ft_strdel(&files[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **lines)
{
	static char		*files[65535];
	char			buf[BUFF_SIZE + 1];
	char			*tmp_file;
	long			bytes_read;

	if (fd < 0 || !lines)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (!files[fd])
			files[fd] = ft_strnew(1);
		tmp_file = ft_strjoin(files[fd], buf);
		free(files[fd]);
		files[fd] = tmp_file;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bytes_read < 0)
		return (-1);
	else if (bytes_read == 0 && (files[fd] == NULL || files[fd][0] == '\0'))
		return (0);
	return (ft_putline(files, lines, fd, bytes_read));
}
/*
char		*ft_strnew_(size_t size)
{
	void	*mem;

	mem = (char *)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, '\0', size + 1);
	return (mem);
}
*/