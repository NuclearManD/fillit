/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include/solver.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:16:16 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 19:16:16 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "libft.h"
# include "fillit_maps.h"

int				ft_sqrt(int val);

t_map			*solve(t_list *tetrominoes, int len);
int				attempt_size(t_list *tetrominoes, t_map **map);

#endif
