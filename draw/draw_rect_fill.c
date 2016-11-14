/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 23:16:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 02:29:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_rect_fill(t_draw *d, t_rect rect, unsigned int color)
{
	t_line		line;
	const int	m = (rect.end.y - rect.start.y < 0) ? -1 : 1;

	line = draw_make_line(rect.start.x, rect.start.y,
			rect.end.x, rect.start.y);
	while (line.start.y != rect.end.y)
	{
		draw_line(d, line, color);
		line.start.y += m;
		line.end.y += m;
	}
	draw_line(d, line, color);
}
