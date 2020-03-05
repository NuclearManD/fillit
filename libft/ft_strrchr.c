/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduarte- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:17:13 by cduarte-          #+#    #+#             */
/*   Updated: 2020/02/20 10:17:16 by cduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			r = i;
		}
		i++;
	}
	if (!c)
		return ((char *)s + i);
	if (c && (r != 0 || *s == c))
		return ((char *)s + r);
	return (NULL);
}
