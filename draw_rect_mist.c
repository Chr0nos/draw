/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_mist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:44:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:19:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_rect_mist(t_draw *d, const t_rect rect, size_t pixels,
	unsigned int color)
{
	t_v2i	p;
	int		dx;
	int		dy;

	d->color = color;
	dx = rect.end.x - rect.start.x;
	dy = rect.end.y - rect.start.y;
	while (pixels--)
	{
		p.x = rect.start.x + rand() % dx;
		p.y = rect.start.y + rand() % dy;
		draw_px(d, p);
	}
}
