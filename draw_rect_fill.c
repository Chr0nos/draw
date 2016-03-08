/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 23:16:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 21:52:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_rect_fill(t_mlx *x, t_rect *rect, int color)
{
	t_line		line;
	const int	m = (rect->end.y - rect->start.y < 0) ? -1 : 1;

	line = draw_make_line(rect->start.x, rect->start.y,
			rect->end.x, rect->start.y);
	while (line.start.y != rect->end.y)
	{
		draw_line(x, &line, color);
		line.start.y += m;
		line.end.y += m;
	}
	draw_line(x, &line, color);
}
