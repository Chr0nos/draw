/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 02:31:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		draw_rect(t_draw *d, t_rect rect, unsigned int color)
{
	t_line	(*f)(int, int, int, int);

	f = draw_make_line;
	draw_line(d,
		f(rect.start.x, rect.start.y, rect.end.x, rect.start.y), color);
	draw_line(d,
		f(rect.end.x, rect.start.y, rect.end.x, rect.end.y), color);
	draw_line(d,
		f(rect.end.x, rect.end.y, rect.start.x, rect.end.y), color);
	draw_line(d,
		f(rect.start.x, rect.start.y, rect.start.x, rect.end.y), color);
}
