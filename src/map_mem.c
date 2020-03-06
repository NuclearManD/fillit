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
#include "libft.h"
#include <stdlib.h>

/*
** These functions are intended to be very fast, so any unnecessary checks are
** skipped.
*/

t_map		*make_map(int x, int y)
{
	t_map	*out;
	void	*mem_chunk;
	int		i;

	mem_chunk = malloc(sizeof(char *) * x + x * y);
	ft_bzero(mem_chunk, sizeof(char *) * x + x * y);
	out = (t_map *)malloc(sizeof(t_map));
	out->data = (char **)mem_chunk;
	i = -1;
	while (++i < x)
		out->data[i] = &(mem_chunk[sizeof(char *) * x + i * y]);
	out->size_x = x;
	out->size_y = y;
	return (out);
}

t_map		*copy_map(t_map *map)
{
	t_map	*out;
	void	*mem_chunk;
	int		i;
	int		x;
	int		y;

	x = map->size_x;
	y = map->size_y;
	mem_chunk = malloc(sizeof(char *) * x + x * y);
	out = (t_map *)malloc(sizeof(t_map));
	out->data = (char **)mem_chunk;
	i = -1;
	while (++i < x)
		out->data[i] = &(mem_chunk[sizeof(char *) * x + i * y]);
	out->size_x = x;
	out->size_y = y;
	ft_memcpy(&(out->data[x]), &(map->data[x]), x * y);
	return (out);
}

void		free_map(t_map *map)
{
	free(map->data);
	free(map);
}
