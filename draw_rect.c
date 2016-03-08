/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 21:54:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		draw_rect(t_mlx *x, t_rect *rect, int color)
{
	t_line	line;
	t_line	(*f)(int, int, int, int);

	f = draw_make_line;
	line = f(rect->start.x, rect->start.y, rect->end.x, rect->start.y);
	draw_line(x, &line, color);
	line = f(rect->end.x, rect->start.y, rect->end.x, rect->end.y);
	draw_line(x, &line, color);
	line = f(rect->end.x, rect->end.y, rect->start.x, rect->end.y);
	draw_line(x, &line, color);
	line = f(rect->start.x, rect->start.y, rect->start.x, rect->end.y);
	draw_line(x, &line, color);
}
