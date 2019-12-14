/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:09:58 by kbelov            #+#    #+#             */
/*   Updated: 2019/12/12 13:10:02 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initiate_heat_map(t_state *s)
{
	int n;
	int x;

	n = -1;
	while (++n < s->map_n)
	{
		x = -1;
		while (++x < s->map_x)
		{
			if (s->map[n][x] == '.')// || s->map[n][x] == s->p_char)
				s->hmap[n][x] = 0;
			else if (s->map[n][x] == s->p_char)
				s->hmap[n][x] = -1;
			else if (s->map[n][x] == s->e_char)
				s->hmap[n][x] = -2;
		}
	}
}

void	heat_map(t_state *s)
{
	int n;
	int x;
	int	continue_heating;
	int	i;

	i = 0;
	continue_heating = 1;
	while (continue_heating && ++i < 256)
	{
		continue_heating = 0;
		n = -1;
		while (++n < s->map_n)
		{
			x = -1;
			while (++x < s->map_x)
			{
				if (s->hmap[n][x] == 0)
				{
					heat_cell(s, n, x);
					continue_heating = 1;
				}
			}
		}
		//fprintf(stderr, "****************************************************\n");
		//print_matrix_test_int(s->hmap, s->map_n, s->map_x);
		//fprintf(stderr, "====================================================\n");
	}
	n = -1;
	while (++n < s->map_n)
	{
		x = -1;
		while (++x < s->map_x)
		{
			if (s->hmap[n][x] == 0)
				s->hmap[n][x] = 256;
		}
	}
}

void	heat_cell(t_state *s, int n, int x)
{
	int	top;
	int right;
	int bottom;
	int left;

	top = 0;
	right = 0;
	bottom = 0;
	left = 0;
	if (n - 1 >= 0 && s->hmap[n - 1][x] != -1)
		top = s->hmap[n - 1][x];
	if (x + 1 <= s->map_x && s->hmap[n][x + 1] != -1)
		right = s->hmap[n][x + 1];
	if (n + 1 < s->map_n && s->hmap[n + 1][x] != -1)
		bottom = s->hmap[n + 1][x];
	if (x - 1 >= 0 && s->hmap[n][x - 1] != -1)
		left = s->hmap[n][x - 1];
	if (top == -2 || right == -2 || bottom == -2 || left == -2)
		s->hmap[n][x] = 1;
	else if (top > 0 || right > 0 || bottom > 0 || left > 0)
		s->hmap[n][x] = ft_max(ft_max(top, right), ft_max(bottom, left)) + 1;
	//else if (top == -1 || right == -1 || bottom == -1 || left == -1)
		//s->hmap[n][x] = 10;
}
