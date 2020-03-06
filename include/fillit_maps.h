/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_maps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:26:53 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 15:26:53 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_MAPS_H
# define FILLIT_MAPS_H

typedef struct	s_map {
	int		size_x;
	int		size_y;
	char	**data;
}				t_map;

t_map			*make_map(int x, int y);
void			free_map(t_map *map);

/*
** attempt_map_loc checks using map_intersect, returning 0 on failure.
** Thus you typically needn't call map_intersect.
**
** attempt_map_insert finds a spot in the map that the tetromino fits,
** returning 0 on failure.
*/

int				map_intersect(t_map *map, t_map *tetromino, int x, int y);
int				attempt_map_loc(t_map *map, t_map *tetromino, int x, int y);
int				attempt_map_insert(t_map *map, t_map *tetromino);
void			print_map(t_map *map);

#endif
