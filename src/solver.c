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

/*
** This function just swaps the first and last element of a list.
** List size MUST be at least one or you WILL segfault.  Do not make this a
** possibility.  The caller should check list size, thus the call can be
** avoided completely and further optimizations can be made. CYFP!!!
*/

void			reset_list(t_list **tetrominoes)
{
	t_list	*last;
	t_list	*old_first;

	last = *tetrominoes;
	if (!last->next)
		return ;
	while (last->next)
		last = last->next;
	old_first = *tetrominoes;
	*tetrominoes = old_first->next;
	last->next = old_first;
	old_first->next = NULL;
}

/*
** n should never be 0.  Any positive int is OK, on end of list it returns 0.
** If still in the list then the next n value is given
** On end of list, the list is reset to it's original state (assuming function
** was called in order n = [1,2,3...EOL])
*/

int				reorder_list(t_list **tetrominoes, int n)
{
	int		count;
	t_list	*idx;
	void	*tmp;

	idx = *tetrominoes;
	count = 0;
	while (n && idx->next)
	{
		idx = idx->next;
		count++;
		n--;
	}
	tmp = idx->content;
	idx->content = (*tetrominoes)->content;
	(*tetrominoes)->content = tmp;
	if (n)
	{
		reset_list(tetrominoes);
		return (0);
	}
	return (count + 1);
}

int				attempt_size(t_list *tetrominoes, t_map **map)
{
	t_map	*map_cpy;
	int		cnt;

	cnt = 1;
	while (cnt)
	{
		map_cpy = copy_map(*map);
		if (attempt_map_insert(map_cpy, tetrominoes->content))
		{
			if (tetrominoes->next)
			{
				if (attempt_size(tetrominoes->next, &map_cpy))
				{
					free_map(*map);
					*map = map_cpy;
					return (1);
				}
			}
			else
			{
				free_map(*map);
				*map = map_cpy;
				return (1);
			}
		}
		free_map(map_cpy);
		cnt = reorder_list(&tetrominoes, cnt);
	}
	return (0);
}

t_map			*solve(t_list *tetrominoes, int len)
{
	int		current_map_size;
	t_map	*map;

	current_map_size = ft_sqrt(len * 4);
	while (1)
	{
		map = make_map(current_map_size, current_map_size);
		if (attempt_size(tetrominoes, &map))
			return (map);
		free_map(map);
		current_map_size++;
	}
}
