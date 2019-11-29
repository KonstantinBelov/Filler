/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:34:00 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/22 20:34:02 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

//# include "libft/libft.h"
# include "get_next_line.h"

typedef	struct	s_state
{
	int map_x;
	int map_n;
	int player_n;
}				t_state;

int				main(void);
void    		filler(t_state *state, char **line);
void			del_state(t_state *state);

#endif
