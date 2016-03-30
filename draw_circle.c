/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:18:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 15:20:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		draw_circle_px(t_mlx *x, const t_point *p, const t_circle *c,
		unsigned int color)
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
		draw_px(x, &px, color);
	}
}

void			draw_circle(t_mlx *x, const t_circle *circle,
	unsigned int color)
{
	t_point	p;
	int		d;

	p.x = 0;
	p.y = circle->radius;
	d = p.y - 1;
	while (p.y >= p.x)
	{
		draw_circle_px(x, &p, circle, color);
		if (d >= (p.x * 2))
			d -= (2 * p.x++) + 1;
		else if (d < (2 * (circle->radius - p.y)))
			d += (2 * p.y--) - 1;
		else
			d += 2 * (p.y-- - p.x++ - 1);
	}
}
