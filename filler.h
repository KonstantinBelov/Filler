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
	int		map_n;
	int		map_x;
	int		player_n;
	char	**map;
	char	**piece;
}				t_state;

int				main(void);
void			init_state(t_state *s);
//void    		filler(t_state *s, char **line);
void			parse_player(t_state *s, char **line);
void			parse_map(t_state *s, char **line);
void			parse_peace(t_state *s, char **line);
void			heat_map(t_state *s);
void			place_piece(t_state *s);
//void			del_state(t_state *s);

#endif
