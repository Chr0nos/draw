/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_mist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:44:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 22:02:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdlib.h>

void	draw_rect_mist(t_mlx *x, const t_rect *rect, size_t pixels, int color)
{
	t_point	p;
	int		dx;
	int		dy;

	dx = rect->end.x - rect->start.x;
	dy = rect->end.y - rect->start.y;
	while (pixels--)
	{
		p.x = rect->start.x + rand() % dx;
		p.y = rect->start.y + rand() % dy;
		draw_px(x, &p, color);
	}
}
