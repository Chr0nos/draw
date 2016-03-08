/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/09 12:53:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "libft.h"

inline static void	draw_flat_line(t_mlx *x, t_line line, int color,
		int variance)
{
	while (line.start.x != line.end.x)
	{
		draw_px(x, &line.start, color);
		line.start.x += variance;
	}
}

inline static void	draw_vertical_line(t_mlx *x, t_line line, int color,
		int variance)
{
	while (line.start.y != line.end.y)
	{
		draw_px(x, &line.start, color);
		line.start.y += variance;
	}
}

inline static void	draw_line_bresemham(t_mlx *x, t_line line, int color,
		t_point *variance)
{
	int		err;

	if (line.dx < 0)
		line.dx = -line.dx;
	if (line.dy < 0)
		line.dy = -line.dy;
	err = -line.dx >> 1;
	while (line.start.x != line.end.x)
	{
		draw_px(x, &line.start, color);
		err += line.dy;
		while (err > 0)
		{
			draw_px(x, &line.start, color);
			err -= line.dx;
			line.start.y += variance->y;
		}
		line.start.x += variance->x;
	}
}

void				draw_line(t_mlx *x, t_line *line, int color)
{
	t_point		variance;

	variance.x = (line->end.x - line->start.x < 0) ? -1 : 1;
	variance.y = (line->end.y - line->start.y < 0) ? -1 : 1;
	if ((line->dx == 0) && (line->dy == 0))
		draw_px(x, &line->start, color);
	else if (line->dy == 0)
		draw_flat_line(x, *line, color, variance.x);
	else if (line->dx == 0)
		draw_vertical_line(x, *line, color, variance.y);
	else
		draw_line_bresemham(x, *line, color, &variance);
}
