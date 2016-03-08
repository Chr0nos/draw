/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raster_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:25:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 15:29:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** this function convert 2 3d vectors into a 2d line using Z
*/

t_line	draw_raster_line(t_vector v1, t_vector v2, t_matrix *transform)
{
	t_point		p1;
	t_point		p2;

	p1 = draw_raster_px(v1, transform);
	p2 = draw_raster_px(v2, transform);
	return (draw_make_line(p1.x, p1.y, p2.x, p2.y));
}
