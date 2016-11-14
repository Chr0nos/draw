/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raster_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:25:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:19:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** this function convert 2 3d vectors into a 2d line using Z
*/

t_line	draw_raster_line(t_v3f v1, t_v3f v2, t_matrix *transform)
{
	t_v2i		p1;
	t_v2i		p2;

	p1 = draw_raster_px(v1, transform);
	p2 = draw_raster_px(v2, transform);
	return (draw_make_line(p1.x, p1.y, p2.x, p2.y));
}
