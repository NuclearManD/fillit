/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:25:26 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 15:25:26 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_maps.h"

int				map_intersect(t_map *map, t_map *tetromino, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetromino->size_x && i + x < map->size_x)
	{
		j = 0;
		while (j < tetromino->size_y || j + y >= map->size_y)
		{
			if ((!!map->data[i + x][j + y]) && (!!tetromino->data[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}
