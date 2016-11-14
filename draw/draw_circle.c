/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:18:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:17:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		draw_circle_px(t_draw *d, const t_v2i *p,
	const t_circle *c)
{
	const int	tx[8] = { p->x, p->y, -p->x, -p->y, p->x, p->y, -p->x, -p->y };
	const int	ty[8] = { p->y, p->x, p->y, p->x, -p->y, -p->x, -p->y, -p->x };
	t_v2i		px;
	int			idx;

	idx = 8;
	while (idx--)
	{
		px.x = c->center.x + tx[idx];
		px.y = c->center.y + ty[idx];
		draw_px(d, px);
	}
}

void			draw_circle(t_draw *d, const t_circle *circle,
	unsigned int color)
{
	t_v2i	p;
	int		m;

	draw_setcolor(d, color);
	p.x = 0;
	p.y = circle->radius;
	m = p.y - 1;
	while (p.y >= p.x)
	{
		draw_circle_px(d, &p, circle);
		if (m >= (p.x * 2))
			m -= (2 * p.x++) + 1;
		else if (m < (2 * (circle->radius - p.y)))
			m += (2 * p.y--) - 1;
		else
			m += 2 * (p.y-- - p.x++ - 1);
	}
}
