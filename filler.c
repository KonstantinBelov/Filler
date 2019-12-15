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
    s->hmap = NULL;
    s->piece_n = 0;
    s->piece_x = 0;
    s->piece = NULL;
    s->n = 0;
    s->x = 0;
}

void	parse_player(t_state *s, char **line)
{
    //write(2, "parsing player\n", 15);
    get_next_line(0, line);
    //fprintf(stderr, "got line: %s\n", *line);
    if (ft_strstr(*line, "p1 : "))
    {
        s->player_n = 1;
        //write(2, "s->player saved as 1\n", 21);
    }
    //else if (ft_strstr(*line, "p2 : [players/kbelov.filler]"))
    else if (ft_strstr(*line, "p2 : "))
        s->player_n = 2;
    if (s->player_n == 1)
    {
        s->p_char = 'O';
        s->e_char = 'X';
        //write(2, "s->p_char saved as O\n", 21);
    }
    else if (s->player_n == 2)
    {
        s->p_char = 'X';
        s->e_char = 'O';
    }
}

void	parse_map(t_state *s, char **line)
{
	int i;
    
    i = -1;
    //get_next_line(0, line);
    s->map_n = ft_atoi(*line + 8);
    s->map_x = ft_atoi(*line + 10);
    s->map = (char **)malloc(s->map_n * sizeof(char *));
    s->hmap = (int **)malloc(s->map_n * sizeof(int *));
    while (++i < s->map_n)
    {
        s->map[i] = (char *)malloc((s->map_x + 1) * sizeof(char));
        s->hmap[i] = (int *)malloc((s->map_x + 1) * sizeof(int));
    }
    i = -1;
    get_next_line(0, line);
    while (++i < s->map_n)
	{
		get_next_line(0, line);
        s->map[i] = ft_strsub(*line, 4, s->map_x);
	}
}

int 	parse_piece(t_state *s, char **line)
{
    int i;

    i = -1;
    get_next_line(0, line);
    s->piece_n = ft_atoi(*line + 6);
    s->piece_x = ft_atoi(*line + 8);
    if (!(s->piece = (char **)malloc(s->piece_n * sizeof(char *))))
        return (-1);
    while (++i < s->piece_n)
    {
        get_next_line(0, line);
        if (!(s->piece[i] = (char *)malloc((s->piece_x + 1) * sizeof(char))))
            return (-1);
        s->piece[i] = ft_strdup(*line);
    }
    return (0);
}

int		main(void)
{
    t_state *s;
    char    *line;

    //line = malloc(sizeof(char **));
    s = malloc(sizeof(t_state));
    //line = NULL;
    //*line = (char *)malloc((sizeof(char) * 256));
    init_state(s);
    //write(2, "state inited\n", 12);
    //get_next_line__(0, line);
    //write(2, "gnl1\n", 11);
    parse_player(s, &line);
    while (get_next_line(0, &line))
    {
        //if (ft_strstr(line, "== O fin:"))
        //    return (1);
        //write(2, "axes x read\n", 12);
        //write(2, "first line map read\n", 20);
        parse_map(s, &line);
        //write(2, "map parsed\n", 11);
        //print_matrix_test(s->map, s->map_n, s->map_x);
        parse_piece(s, &line);
        //print_matrix_test(s->piece, s->piece_n, s->piece_x);
        initiate_heat_map(s);
        //print_matrix_test_int(s->hmap, s->map_n, s->map_x);
        heat_map(s);
        //write(2, "map heated\n", 11);
        //write(2, "1) about to start looking for a place\n", 38);
        //print_matrix_test_int(s->hmap, s->map_n, s->map_x);
        find_place(s);
        //write(2, "4) about to place piece\n", 24);
        place_piece(s);
        //write(2, "piece placed\n", 13);
        del_maps(s);
    }
    //ft_strdel(&line);
    free(line);
    //del_maps(s);
    free(s);
    //while (1)
     //   ;
    return (0);
}
