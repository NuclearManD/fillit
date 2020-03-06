/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:34:32 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 16:34:32 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_maps.h"
#include <stdlib.h>

/*
** These functions are intended to be very fast, so any unnecessary checks are
** skipped.
*/

t_map		*make_map(int x, int y)
{
	t_map	*out;
	int		*nbrs;
	void	*mem_chunk;
	int		i;

	mem_chunk = (int **)malloc(sizeof(int *) * x + sizeof(int) * x * y);
	out = (t_map *)malloc(sizeof(t_map));
	out->data = (int **)memory_chunk;
	i = -1;
	while (++i < x)
		out->data[x] = &(memory_chunk[sizeof(int *) + i * y * sizeof(int)]);
	return (out);
}

void		free_map(t_map *map)
{
	free(map->data);
	free(map);
}
