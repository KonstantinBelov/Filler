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
	int		player_n;
	char	p_char;
	char	e_char;
	int		map_n;
	int		map_x;
	char	**map;
	int		**hmap;
	int		piece_n;
	int		piece_x;
	char	**piece;
	int		n;
	int		x;
}				t_state;

int				main(void);
void			init_state(t_state *s);
void			parse_player(t_state *s, char **line);
void			parse_map(t_state *s, char **line);
int				parse_piece(t_state *s, char **line);
void			initiate_heat_map(t_state *s);
void			heat_map(t_state *s);
void			heat_cell(t_state *s, int n, int x);
void			find_place(t_state *s);
int				try_piece(t_state *s, int n, int x);
int				calc_score(t_state *s, int n, int x);
void			place_piece(t_state *s);
//void			del_state(t_state *s);
//void    		filler(t_state *s, char **line);

void			print_matrix_test(char **matrix, int n, int x);
void			print_matrix_test_int(int **matrix, int n, int x);
char			*ft_strstr_(const char *haystack, const char *needle);

#endif
