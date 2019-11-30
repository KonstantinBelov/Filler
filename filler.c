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

// void    del_state(t_state *state)
// {

// }
void    init_state(t_state *s)
{
    s->map_n = 0;
    s->map_x = 0;
    s->player_n = 0;
    s->map_n = NULL;
    s->map_x = NULL;
}

void	parse_player(t_state *s, char **line)
{
	if (ft_strstr(*line, "p1 : [players/kbelov.filler]"))
        s->player_n = 1;
    else if (ft_strstr(*line, "p2 : [players/kbelov.filler]"))
        s->player_n = 2;
    //ft_strdel(line);
    get_next_line(0, line);
	s->map_n = ft_atoi(*line);
    s->map_x = ft_atoi(*line + s->map_n);
}

void	parse_map(t_state *s, char **line)
{
	while (!ft_strstr(*line, "Piece"))
	{
		
	}
}

int		main(void)
{
    t_state *s;
    char    **line;

    line = NULL;
    s = NULL;
    init_state(s);
    get_next_line(0, line);
    if (s->player_n == 0)
		parse_player(s, line);
	else
		get_next_line(0, line);
	get_next_line(0, line);
    //printf("%d %d\n", s->map_n, s->map_x);
    //ft_strdel(line);
    parse_map(s, line);
    parse_peace(s, line);
    heat_map(s);
    place_peace(s);
    //filler(s, line);
	ft_strdel(line);
    //del_state(s);
    return (0);
}
