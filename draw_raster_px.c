/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raster_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:15:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 18:13:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** this function convert a 3d vector into a 2d point using Z
*/

t_point		draw_raster_px(t_vector v, t_matrix *transform)
{
	t_point		p;

	v = draw_vector_transform(v, transform);
	p.x = (int)v.x;
	p.y = (int)v.y;
	return (p);
}
