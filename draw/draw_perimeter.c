/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perimeter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:14:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:18:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_perimeter(t_draw *d, const t_v2i *tab, size_t size,
	unsigned int color)
{
	const t_v2i		*point;
	const t_v2i		*lpoint;
	size_t			p;

	if (!size)
		return ;
	d->color = color;
	if (size == 1)
	{
		draw_px(d, *tab);
		return ;
	}
	p = 1;
	point = tab;
	while (p < size)
	{
		lpoint = point;
		point = &tab[p];
		draw_line(d, draw_make_line(point->x, point->y, lpoint->x, lpoint->y),
			color);
		p++;
	}
	draw_line(d, draw_make_line(point->x, point->y, tab[0].x,
		(tab[0].y > 0) ? tab[0].y - 1 : tab[0].y), color);
}
