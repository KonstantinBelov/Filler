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

void	find_place(t_state *s)
{
    int n;
	int x;
	//int	n_best;
	//int	x_best;
	int	best_score;
	int	score;

	s->n = 0;
	s->x = 0;
	best_score = INT_MAX;
	score = 0;
	//write(2, "2) actually looking for a place\n", 32);
	//fprintf(stderr, "s->p_char = %c\n", s->p_char);
	n = -1;
	while (++n + s->piece_n <= s->map_n)
	{
		x = -1;
		while (++x + s->piece_x <= s->map_x)
		{
			//fprintf(stderr, "n & x values: %d %d\n", n, x);
			//if (s->map[n][x] == s->p_char/*|| s->map[n][x] == s->p_char + 32*/)
			//{
			if (try_piece(s, n, x))
			{
				score = calc_score(s, n, x);
				if (score < best_score)
				{
					s->n = n;
					s->x = x;
					best_score = score;
					//write(2, "3) place found\n", 15);
				}
			}
			//}
		}
	}
}

int		try_piece(t_state *s, int n, int x)
{
	int contacts;
	int i;
	int j;

	i = -1;
	contacts = 0;
	while (++i < s->piece_n)
	{
		j = -1;
		while (++j < s->piece_x)
		{
			if (s->piece[i][j] == '*')
			{
				if (s->map[i + n][j + x] == s->e_char)
					return (0);
				if (s->map[i + n][j + x] == s->p_char)
					contacts++;
				if (contacts > 1)
					return (0);
			}
		}
	}
	if (contacts == 1)
		return (1);
	return (0);
}

int		calc_score(t_state *s, int n, int x)
{
	int score;
	int i;
	int j;

	score = 0;
	i = -1;
	while (++i < s->piece_n)
	{
		j = -1;
		while (++j < s->piece_x)
		{
			if (s->hmap[i + n][j + x] > 0 && s->piece[i][j] == '*')
				score += s->hmap[i + n][j + x];
		}
	}
	return (score);
}

void	place_piece(t_state *s)
{
	//write(2, "5) placing piece\n", 17);
	ft_putnbr(s->n);
	ft_putchar(' ');
	ft_putnbr(s->x);
	ft_putchar('\n');
}

void    del_maps(t_state *s)
{
	int n;

	n = -1;
	while (++n < s->map_n)
	{
		//ft_strdel(&(s->map[n]));
		//if (s->map[n])
		free(s->map[n]);
		//if (s->hmap[n])
		free(s->hmap[n]);
	}
	//if (s->map)
	free(s->map);
	//if (s->hmap)
	free(s->hmap);
	n = -1;
	while (++n < s->piece_n)
	{
		//ft_strdel(&(s->piece[n]));
		//if (s->piece[n])
		free(s->piece[n]);
	}
	//if (s->piece)
	free(s->piece);
}

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
