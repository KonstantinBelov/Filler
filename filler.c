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

void    init_state(t_state *s)
{
    s->player_n = 0;
    s->map_n = 0;
    s->map_x = 0;
    s->map = NULL;
    s->piece_n = 0;
    s->piece_x = 0;
    s->piece = NULL;
}

void	parse_player(t_state *s, char **line)
{
	char *map_row;
    
    if (ft_strstr(*line, "p1 : [players/kbelov.filler]"))
        s->player_n = 1;
    else if (ft_strstr(*line, "p2 : [players/kbelov.filler]"))
        s->player_n = 2;
    get_next_line(0, line);
	s->map_n = ft_atoi(*line + 8);
    s->map_x = ft_atoi(*line + 10);
    map_row = ft_strnew(s->map_x + 1);
    s->map = (char **)malloc((s->map_n + 1) * sizeof(map_row));
}

void	parse_map(t_state *s, char **line)
{
	while (!ft_strstr(*line, "Piece"))
	{
		*s->map = ft_strsub(*line, 4, s->map_x);
        s->map++;
        get_next_line(0, line);
	}
}

void	parse_piece(t_state *s, char **line)
{
	char *piece_row;
    
    s->piece_n = ft_atoi(*line + 6);
    s->piece_x = ft_atoi(*line + 8);
    piece_row = ft_strnew(s->piece_x + 1);
    s->piece = (char **)malloc((s->piece_n + 1) * sizeof(piece_row));
    while (get_next_line(0, line))
	{
		*s->map = ft_strdup(*line);
        s->piece++;
	}
}

int		main(void)
{
    t_state *s;
    char    **line;

    line = malloc(sizeof(char **));
    s = malloc(sizeof(t_state *));
    init_state(s);
    get_next_line(0, line);
    if (ft_strstr(*line, "kbelov.filler"))
		parse_player(s, line);
	get_next_line(0, line);
	get_next_line(0, line);
    parse_map(s, line);
    parse_piece(s, line);
    heat_map(s);
    place_piece(s);
	ft_strdel(line);
    //del_state(s);
    return (0);
}
