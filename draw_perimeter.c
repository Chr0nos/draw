/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perimeter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:14:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 15:19:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_perimeter(t_mlx *x, const t_point *tab, size_t size,
	unsigned int color)
{
	const t_point	*point;
	const t_point	*lpoint;
	size_t			p;
	t_line			line;

	if (!size)
		return ;
	if (size == 1)
	{
		draw_px(x, tab, color);
		return ;
	}
	p = 1;
	point = tab;
	while (p < size)
	{
		lpoint = point;
		point = &tab[p];
		line = draw_make_line(point->x, point->y, lpoint->x, lpoint->y);
		draw_line(x, &line, color);
		p++;
	}
	line = draw_make_line(point->x, point->y, tab[0].x,
		(tab[0].y > 0) ? tab[0].y - 1 : tab[0].y);
	draw_line(x, &line, color);
}
