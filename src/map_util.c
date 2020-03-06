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
#include <unistd.h>

/*
** These functions are intended to be very fast, so any unnecessary checks are
** skipped.
*/

int			map_intersect(t_map *map, t_map *tetromino, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetromino->size_x && i + x < map->size_x)
	{
		j = 0;
		while (j < tetromino->size_y && j + y < map->size_y)
		{
			if ((!!map->data[i + x][j + y]) && (!!tetromino->data[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			attempt_map_place(t_map *map, t_map *tetromino, int x, int y)
{
	int i;
	int j;

	if (!map_intersect(map, tetromino, x, y))
		return (0);
	i = 0;
	while (i < tetromino->size_x && i + x < map->size_x)
	{
		j = 0;
		while (j < tetromino->size_y && j + y < map->size_y)
		{
			if (!!tetromino->data[i][j])
				map->data[i + x][j + y] = tetromino->data[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

/*
** int main() {
** 	int arr[4][4] = {	{1, 1, 0, 1},
** 						{1, 0, 0, 0},
** 						{1, 0, 0, 0},
** 						{1, 1, 1, 1}};
** 	int *arrd[4] = {arr[0], arr[1], arr[2], arr[3]};
** 	t_map map1 = {4, 4, arrd};
** 	int arr2[2][2] = {{1,1},{1,1}};
** 	int *tetd[2] = {arr2[0], arr[1]};
** 	t_map tet = {2, 2, tetd};
**
** 	printf("%i\n", map_intersect(&map1, &tet, 0, 0));
** 	printf("%i\n", map_intersect(&map1, &tet, 1, 1));
** 	printf("%i\n", map_intersect(&map1, &tet, 1, 0));
** 	printf("%i\n", map_intersect(&map1, &tet, 0, 1));
** 	printf("%i\n", map_intersect(&map1, &tet, 2, 1));
** 	printf("%i\n", map_intersect(&map1, &tet, 1, 2));
** 	return (-100000);
** }
*/
