/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 18:51:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include <SDL2/SDL.h>

inline static void	draw_flat_line(SDL_Renderer *r, t_line line,
	int variance)
{
	while (line.start.x != line.end.x)
	{
		SDL_RenderDrawPoint(r, line.start.x, line.start.y);
		line.start.x += variance;
	}
}

inline static void	draw_vertical_line(SDL_Renderer *r, t_line line,
		int variance)
{
	while (line.start.y != line.end.y)
	{
		SDL_RenderDrawPoint(r, line.start.x, line.start.y);
		line.start.y += variance;
	}
}

inline static void	draw_line_bresemham(SDL_Renderer *r, t_line line,
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
		SDL_RenderDrawPoint(r, line.start.x, line.start.y);
		err += line.dy;
		while (err > 0)
		{
			SDL_RenderDrawPoint(r, line.start.x, line.start.y);
			err -= line.dx;
			line.start.y += variance->y;
		}
		line.start.x += variance->x;
	}
}

void				draw_line(SDL_Renderer *r, t_line *line, unsigned int color)
{
	t_point		variance;

	draw_setcolor(r, color);
	variance.x = (line->end.x - line->start.x < 0) ? -1 : 1;
	variance.y = (line->end.y - line->start.y < 0) ? -1 : 1;
	if ((line->dx == 0) && (line->dy == 0))
		SDL_RenderDrawPoint(r, line->start.x, line->start.y);
	else if (line->dy == 0)
		draw_flat_line(r, *line, variance.x);
	else if (line->dx == 0)
		draw_vertical_line(r, *line, variance.y);
	else
		draw_line_bresemham(r, *line, &variance);
}
