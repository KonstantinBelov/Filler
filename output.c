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
			if (s->map[n][x] == '.')
				s->hmap[n][x] = 0;
			else if (s->map[n][x] == s->p_char)
				s->hmap[n][x] = INT_MAX;
			else if (s->map[n][x] == s->e_char)
				s->hmap[n][x] = INT_MIN;
		}
	}
}

void	heat_map(t_state *s)
{
	int n;
	int x;
	int	continue_heating;

	continue_heating = 1;
	while (continue_heating)
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
	if (n - 1 >= 0)
		top = s->map[n - 1][x];
	if (x + 1 <= s->map_x)
		right = s->map[n][x + 1];
	if (n + 1 < s->map_n)
		bottom = s->map[n + 1][x];
	if (x - 1 >= 0)
		left = s->map[n][x - 1];
	if (top == INT_MIN || right == INT_MIN || bottom == INT_MIN || left == INT_MIN)
		s->hmap[n][x] = 1;
	else if (top || right || bottom || left)
		s->hmap[n][x] = ft_max(ft_max(top, right), ft_max(bottom, left)) + 1;
}

void	find_place(t_state *s)
{
    int n;
	int x;

	//write(2, "2) actually looking for a place\n", 32);
	fprintf(stderr, "s->p_char = %c\n", s->p_char);
	n = -1;
	while (++n < s->map_n)
	{
		x = -1;
		while (++x < s->map_x)
		{
			//write(2, &n, 4);
			//write(2, &x, 4);
			//fprintf(stderr, "n & x values: %d %d\n", n, x);
			if (s->map[n][x] == s->p_char/*|| s->map[n][x] == s->p_char + 32*/)
			{
				s->n = n;
				s->x = x;
				//write(2, "3) place found\n", 15);
				if (try_piece(s, n, x))
				{
					//save_
				}
			}
		}
	}
}

int		try_piece(t_state *s, int n, int x)
{
	if (n + s->piece_n > s->map_n)
	{

	}
	if (x + s->piece_x > s->map_x)
	{

	}
	return (0);
}

void	place_piece(t_state *s)
{
	//write(2, "5) placing piece\n", 17);
	s->player_n = 1;
	ft_putnbr(s->n);
	ft_putchar(' ');
	ft_putnbr(s->x);
	ft_putchar('\n');
}

void	print_matrix_test(char **matrix, int n, int x)
{
	int		y;
	int		i;

	y = -1;
	while (++y < n)
	{
		i = -1;
		while (++i < x)
			write(2, &matrix[y][i], 1);
		write (2, "\n", 1);
	}
	//write(1, "\n", 1);
}

void	print_matrix_test_int(int **matrix, int n, int x)
{
	int		y;
	int		i;

	y = -1;
	while (++y < n)
	{
		i = -1;
		while (++i < x)
			write(2, &matrix[y][i], 4);
		write (2, "\n", 1);
	}
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
