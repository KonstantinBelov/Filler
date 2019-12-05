/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:55:56 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/30 19:55:59 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	heat_map(t_state *s)
{
    s->x = 0;
}

void	place_piece(t_state *s)
{
    int n;
	int x;

	n = -1;
	while (++n < s->map_n)
	{
		x = -1;
		while (++x < s->map_x)
		{
			if (s->map[n][x] == s->p_char || s->map[n][x] == s->p_char + 32)
			{
				/*ft_putnbr(n);
				write(1, " ", 1);
				ft_putnbr(x);*/
			}
		}
	}
    write(1, "8 2", 3);
}

void		print_matrix_test(char **matrix, int n, int x)
{
	int		y;
	int		i;

	y = -1;
	while (++y < n)
	{
		i = -1;
		while (++i < x)
			write(1, &matrix[y][i], 1);
		write (1, "\n", 1);
	}
	//write(1, "\n", 1);
}

// void    del_state(t_state *state)
// {

// }

// void    filler(t_state *s, char **line)
// {
//     get_next_line(0, line);
//     ft_strdel(line);
//     //s = NULL;
//     //line = NULL;
//     //write(1, "1 1\n", 4);
//     while(get_next_line(0, line))
//     {

//     }
//     while (!(ft_strstr(line)))
// }
