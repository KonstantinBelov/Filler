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
    int i;

    //write(2, "fuck\n", 11);
    i = -1;
    if (ft_strstr(*line, "p1 : [players/kbelov.filler]"))
        s->player_n = 1;
    else if (ft_strstr(*line, "p2 : [players/kbelov.filler]"))
        s->player_n = 2;
    if (s->player_n == 1)
        s->p_char = 'O';
    else if (s->player_n == 2)
        s->p_char = 'X';
    get_next_line(0, line);
	s->map_n = ft_atoi(*line + 8);
    s->map_x = ft_atoi(*line + 10);
    //write(2, "map heated\n", 11);
    s->map = (char **)malloc(s->map_n * sizeof(char *));
    while (++i < s->map_n)
        s->map[i] = (char *)malloc((s->map_x + 1) * sizeof(char)); 
}

void	parse_map(t_state *s, char **line)
{
	int i;
    
    i = 0;
    while (!ft_strstr(*line, "Piece"))
	{
		s->map[i] = ft_strsub(*line, 4, s->map_x);
        i++;
        get_next_line(0, line);
	}
}

int 	parse_piece(t_state *s, char **line)
{
    int i;

    i = -1;
    s->piece_n = ft_atoi(*line + 6);
    s->piece_x = ft_atoi(*line + 8);
    if (!(s->piece = (char **)malloc(s->piece_n * sizeof(char *))))
        return (-1);
    get_next_line(0, line);
    while (++i < s->piece_n)
    {
        if (!(s->piece[i] = (char *)malloc((s->piece_x + 1) * sizeof(char))))
            return (-1);
        s->piece[i] = ft_strdup(*line);
        get_next_line(0, line);
    }
    return (0);
}

int		main(void)
{
    t_state *s;
    char    **line;

    line = malloc(sizeof(char **));
    s = malloc(sizeof(t_state *));
    init_state(s);
    //write(2, "state inited\n", 12);
    get_next_line(0, line);
    //write(2, "gnl1\n", 11);
    if (ft_strstr(*line, "kbelov.filler"))
		parse_player(s, line);
    //write(2, "player parsed\n", 13);
	get_next_line(0, line);
	get_next_line(0, line);
    parse_map(s, line);
    //print_matrix_test(s->map, s->map_n, s->map_x);
    parse_piece(s, line);
    //print_matrix_test(s->piece, s->piece_n, s->piece_x);
    heat_map(s);
    //write(2, "map heated\n", 11);
    place_piece(s);
    //write(2, "piece placed\n", 13);
	ft_strdel(line);
    //del_state(s);
    return (0);
}
