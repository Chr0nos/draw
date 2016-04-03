/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perimeter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:14:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 18:56:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_perimeter(SDL_Renderer *r, const t_point *tab, size_t size,
	unsigned int color)
{
	const t_point	*point;
	const t_point	*lpoint;
	size_t			p;
	t_line			line;

	if (!size)
		return ;
	if (size == 1)
	{
		draw_px(r, *tab, color);
		return ;
	}
	p = 1;
	point = tab;
	while (p < size)
	{
		lpoint = point;
		point = &tab[p];
		line = draw_make_line(point->x, point->y, lpoint->x, lpoint->y);
		draw_line(r, &line, color);
		p++;
	}
	line = draw_make_line(point->x, point->y, tab[0].x,
		(tab[0].y > 0) ? tab[0].y - 1 : tab[0].y);
	draw_line(r, &line, color);
}
