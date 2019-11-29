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

void    filler(t_state *state, char **line)
{
    //while (get_next_line(1, line) == 1)
    //{

    //}
}

void    del_state(t_state *state)
{

}

int     main(void)
{
    t_state *state;
    char    **line;

    line = NULL;
    state = NULL;
    get_next_line(0, line);
    if (ft_strstr(*line, "p1 : [players/kbelov.filler]"))
        state->player_n = 1;
    else if (ft_strstr(*line, "p2 : [players/kbelov.filler]"))
        state->player_n = 2;
    ft_strdel(line);
    get_next_line(0, line);
    state->map_n = ft_atoi(*line);
    state->map_x = ft_atoi(*line + state->map_n);
    ft_strdel(line);
    while (get_next_line(0, line))
        filler(state, line);
    del_state(state);
    return (0);
}
