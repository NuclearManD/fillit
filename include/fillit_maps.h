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
	int		**data;
}				t_map;

t_map		*make_map(int x, int y);
void		free_map(t_map *map);


/*
** attempt_map_place checks using map_intersect, returning 0 on failure.
** Thus you typically needn't call map_intersect.
*/

int			map_intersect(t_map *map, t_map *tetromino, int x, int y);
int			attempt_map_place(t_map *map, t_map *tetromino, int x, int y);


#endif
