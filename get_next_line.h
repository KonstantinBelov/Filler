/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:40:40 by kbelov            #+#    #+#             */
/*   Updated: 2019/03/19 16:19:23 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);
int		ft_putline(char **files, char **lines, int fd, int rd);
/*
typedef struct	s_line
{
	char				*str;
	int					fd;
	struct s_line		*next;
}				t_line;

int		get_next_line__(const int fd, char **line);
int		len(char *s, int c);
char	*ft_str_ljoin(char **s1, char **s2);
void	get_tail(const int fd, char *buf, t_line **head);
int		reading(int fd, char **line, t_line **head);

char	*ft_strnew_(size_t size);

int		get_next_line(const int fd, char **line);
*/
#endif
