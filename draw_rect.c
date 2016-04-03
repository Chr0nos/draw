/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 18:37:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		draw_rect(SDL_Renderer *r, t_rect *rect, unsigned int color)
{
	t_line	line;
	t_line	(*f)(int, int, int, int);

	f = draw_make_line;
	line = f(rect->start.x, rect->start.y, rect->end.x, rect->start.y);
	draw_line(r, &line, color);
	line = f(rect->end.x, rect->start.y, rect->end.x, rect->end.y);
	draw_line(r, &line, color);
	line = f(rect->end.x, rect->end.y, rect->start.x, rect->end.y);
	draw_line(r, &line, color);
	line = f(rect->start.x, rect->start.y, rect->start.x, rect->end.y);
	draw_line(r, &line, color);
}
