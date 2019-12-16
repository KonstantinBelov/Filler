/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:33:38 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/22 20:33:45 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_state(t_state *s)
{
	s->player_n = 0;
	s->map_n = 0;
	s->map_x = 0;
	s->map = NULL;
	s->hmap = NULL;
	s->piece_n = 0;
	s->piece_x = 0;
	s->piece = NULL;
	s->n = 0;
	s->x = 0;
}

void	parse_player(t_state *s, char **line)
{
	get_next_line(0, line);
	if (ft_strstr(*line, "p1 : "))
		s->player_n = 1;
	else if (ft_strstr(*line, "p2 : "))
		s->player_n = 2;
	if (s->player_n == 1)
	{
		s->p_char = 'O';
		s->e_char = 'X';
	}
	else if (s->player_n == 2)
	{
		s->p_char = 'X';
		s->e_char = 'O';
	}
	free(*line);
}

void	parse_map(t_state *s, char **line)
{
	int i;
	int n_digits;

	n_digits = 1;
	s->map_n = ft_atoi(*line + 8);
	i = s->map_n;
	while (i /= 10)
		n_digits++;
	s->map_x = ft_atoi(*line + 8 + n_digits);
	s->map = (char **)malloc(s->map_n * sizeof(char *));
	s->hmap = (int **)malloc(s->map_n * sizeof(int *));
	i = -1;
	while (++i < s->map_n)
		s->hmap[i] = (int *)malloc((s->map_x + 1) * sizeof(int));
	free(*line);
	get_next_line(0, line);
	free(*line);
	i = -1;
	while (++i < s->map_n)
	{
		get_next_line(0, line);
		s->map[i] = ft_strsub(*line, 4, s->map_x);
		free(*line);
	}
}

int		parse_piece(t_state *s, char **line)
{
	int i;

	i = -1;
	get_next_line(0, line);
	s->piece_n = ft_atoi(*line + 6);
	s->piece_x = ft_atoi(*line + 8);
	free(*line);
	if (!(s->piece = (char **)malloc(s->piece_n * sizeof(char *))))
		return (-1);
	while (++i < s->piece_n)
	{
		get_next_line(0, line);
		s->piece[i] = ft_strdup(*line);
		free(*line);
	}
	return (0);
}

int		main(void)
{
	t_state *s;
	char	*line;

	s = malloc(sizeof(t_state));
	init_state(s);
	parse_player(s, &line);
	while (get_next_line(0, &line))
	{
		parse_map(s, &line);
		parse_piece(s, &line);
		initiate_heat_map(s);
		heat_map(s);
		heat_zeros(s);
		find_place(s);
		place_piece(s);
		del_maps(s);
	}
	free(s);
	return (0);
}
