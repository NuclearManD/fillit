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
#include <stdio.h>

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

int			attempt_map_loc(t_map *map, t_map *tetromino, int x, int y)
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
** TODO: optimize this function so that obviously bad spots are not tested
*/

int			attempt_map_insert(t_map *map, t_map *tetromino)
{
	int x;
	int y;

	y = -1;
	while (++y <= map->size_y - tetromino->size_y)
	{
		x = -1;
		while (++x <= map->size_x - tetromino->size_x)
			if (attempt_map_loc(map, tetromino, x, y))
				return (1);
	}
	return (0);
}

void		print_map(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->data[x][y])
			{
				c = 'A' - 1 + map->data[x][y];
				write(1, &c, 1);
			} else
				write(1, ".", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int main() {
	int arr[4][4] = {	{2, 2, 0, 4},
						{2, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 1, 1}};
	int *arrd[4] = {arr[0], arr[1], arr[2], arr[3]};
	t_map map1 = {4, 4, arrd};
	int arr2[2][2] = {{3,3},{3,3}};
	int *tetd[2] = {arr2[0], arr2[1]};
	t_map tet = {2, 2, tetd};

	print_map(&tet);
	printf("\n");
	print_map(&map1);
	printf("%i\n", map_intersect(&map1, &tet, 0, 0));
	printf("%i\n", map_intersect(&map1, &tet, 1, 1));
	printf("%i\n", map_intersect(&map1, &tet, 1, 0));
	printf("%i\n", map_intersect(&map1, &tet, 0, 1));
	printf("%i\n", map_intersect(&map1, &tet, 2, 1));
	printf("%i\n", map_intersect(&map1, &tet, 1, 2));
	
	attempt_map_insert(&map1, &tet);
	print_map(&map1);
	return (-100000);
}
