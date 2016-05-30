/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raster_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:15:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/30 19:27:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** this function convert a 3d vector into a 2d point using Z
*/

t_point		draw_raster_px(t_vector v, t_matrix *transform)
{
	v = draw_vector_transform(v, transform);
	return ((t_point){(int)v.x, (int)v.y});
}
