/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move_pxlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:32:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 13:43:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <string.h>

t_point	*draw_move_pxlist(t_point *tab, size_t size, int x, int y)
{
	size_t	p;

	p = 0;
	while (p < size)
	{
		tab[p].x += x;
		tab[p].y += y;
		p++;
	}
	return (tab);
}
