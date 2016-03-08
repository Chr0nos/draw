/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_invert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:38:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 21:55:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_rect_invert(t_mlx *x, const t_rect *r)
{
	t_point	p;

	p.y = r->start.y;
	while (p.y <= r->end.y)
	{
		p.x = r->start.x;
		while (p.x <= r->end.x)
		{
			draw_px(x, &p, 0xffffff - draw_get_px(x, &p));
			p.x++;
		}
		p.y++;
	}
}
