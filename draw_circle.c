/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:18:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 18:54:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		draw_circle_px(SDL_Renderer *r, const t_point *p,
	const t_circle *c)
{
	const int	tx[8] = { p->x, p->y, -p->x, -p->y, p->x, p->y, -p->x, -p->y };
	const int	ty[8] = { p->y, p->x, p->y, p->x, -p->y, -p->x, -p->y, -p->x };
	t_point		px;
	int			idx;

	idx = 8;
	while (idx--)
	{
		px.x = c->center.x + tx[idx];
		px.y = c->center.y + ty[idx];
		SDL_RenderDrawPoint(r, px.x, px.y);
	}
}

void			draw_circle(SDL_Renderer *r, const t_circle *circle,
	unsigned int color)
{
	t_point	p;
	int		d;

	draw_setcolor(r, color);
	p.x = 0;
	p.y = circle->radius;
	d = p.y - 1;
	while (p.y >= p.x)
	{
		draw_circle_px(r, &p, circle);
		if (d >= (p.x * 2))
			d -= (2 * p.x++) + 1;
		else if (d < (2 * (circle->radius - p.y)))
			d += (2 * p.y--) - 1;
		else
			d += 2 * (p.y-- - p.x++ - 1);
	}
}
