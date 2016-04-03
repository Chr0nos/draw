/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_mist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:44:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 18:53:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_rect_mist(SDL_Renderer *r, const t_rect *rect, size_t pixels,
	unsigned int color)
{
	t_point	p;
	int		dx;
	int		dy;

	draw_setcolor(r, color);
	dx = rect->end.x - rect->start.x;
	dy = rect->end.y - rect->start.y;
	while (pixels--)
	{
		p.x = rect->start.x + rand() % dx;
		p.y = rect->start.y + rand() % dy;
		SDL_RenderDrawPoint(r, p.x, p.y);
	}
}
