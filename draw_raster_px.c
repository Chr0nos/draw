/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raster_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:15:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:19:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** this function convert a 3d vector into a 2d point using Z
*/

t_v2i		draw_raster_px(t_v3f v, t_matrix *transform)
{
	v = geo_trans(v, transform);
	return ((t_v2i){(int)v.x, (int)v.y});
}
