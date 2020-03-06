/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:39:17 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 17:39:17 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_maps.h"
#include "solver.h"
#include "libft.h"

int				main(int ac, char **av)
{
	t_map *map;
	t_map *tet1;
	t_map *tet2;
	t_list *li;

	if (ac != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(av[0]);
		ft_putstr(" file\n");
		return (0);
	}
	tet1 = make_map(2, 3);
	tet1->data[0][0] = 1;
	tet1->data[0][1] = 1;
	tet1->data[0][2] = 1;
	tet1->data[1][1] = 1;
	tet2 = make_map(1, 4);
	tet2->data[0][0] = 2;
	tet2->data[0][1] = 2;
	tet2->data[0][2] = 2;
	tet2->data[0][3] = 2;
	
	li = ft_lstnew(tet1, 0);
	li->next = ft_lstnew(tet2, 0);
	
	map = solve(li, 2);
	print_map(map);
	return (0);
}
