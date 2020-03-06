/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:14:38 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 19:14:38 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_maps.h"
#include "solver.h"
#include "libft.h"

int				attempt_size(t_list *tetrominoes, t_map *map)
{
	while (tetrominoes)
	{
		if (!attempt_map_insert(map, tetrominoes->content))
		{
			return (0);
		}
		tetrominoes = tetrominoes->next;
	}
	return (1);
}

t_map			*solve(t_list *tetrominoes, int len)
{
	int		current_map_size;
	t_map	*map;

	current_map_size = ft_sqrt(len * 4);
	while (1)
	{
		map = make_map(current_map_size, current_map_size);
		if (attempt_size(tetrominoes, map))
			return (map);
		free_map(map);
		current_map_size++;
	}
}
