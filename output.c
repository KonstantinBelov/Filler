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
	int	best_score;
	int	score;

	s->n = 0;
	s->x = 0;
	best_score = INT_MAX;
	score = 0;
	n = -1;
	while (++n + s->piece_n <= s->map_n)
	{
		x = -1;
		while (++x + s->piece_x <= s->map_x)
		{
			if (try_piece(s, n, x))
				best_score = calc_score(s, n, x, best_score);
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

int		calc_score(t_state *s, int n, int x, int best_score)
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
	if (score < best_score)
	{
		s->n = n;
		s->x = x;
		best_score = score;
	}
	return (best_score);
}

void	place_piece(t_state *s)
{
	ft_putnbr(s->n);
	ft_putchar(' ');
	ft_putnbr(s->x);
	ft_putchar('\n');
}

void	del_maps(t_state *s)
{
	int n;

	n = -1;
	while (++n < s->map_n)
	{
		free(s->map[n]);
		free(s->hmap[n]);
	}
	free(s->map);
	free(s->hmap);
	n = -1;
	while (++n < s->piece_n)
		free(s->piece[n]);
	free(s->piece);
}
