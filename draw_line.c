/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:17:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include <SDL2/SDL.h>

inline static void	draw_line_flatx(t_draw *d, t_line line,
	int variance)
{
	while (line.start.x != line.end.x)
	{
		draw_px(d, line.start);
		line.start.x += variance;
	}
}

inline static void	draw_line_vertical(t_draw *d, t_line line,
		int variance)
{
	while (line.start.y != line.end.y)
	{
		draw_px(d, line.start);
		line.start.y += variance;
	}
}

inline static void	draw_line_bresemham(t_draw *d, t_line line,
	t_v2i *variance)
{
	int		err;

	if (line.dx < 0)
		line.dx = -line.dx;
	if (line.dy < 0)
		line.dy = -line.dy;
	err = -line.dx >> 1;
	while (line.start.x != line.end.x)
	{
		draw_px(d, line.start);
		err += line.dy;
		while (err > 0)
		{
			draw_px(d, line.start);
			err -= line.dx;
			line.start.y += variance->y;
		}
		line.start.x += variance->x;
	}
}

void				draw_line(t_draw *d, t_line line, unsigned int color)
{
	t_v2i		variance;

	d->color = color;
	variance.x = (line.end.x - line.start.x < 0) ? -1 : 1;
	variance.y = (line.end.y - line.start.y < 0) ? -1 : 1;
	if ((line.dx == 0) && (line.dy == 0))
		draw_px(d, line.start);
	else if (line.dy == 0)
		draw_line_flatx(d, line, variance.x);
	else if (line.dx == 0)
		draw_line_vertical(d, line, variance.y);
	else
		draw_line_bresemham(d, line, &variance);
}
