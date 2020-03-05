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

#endif
