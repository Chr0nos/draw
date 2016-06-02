/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_rot_m4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:08:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/03 00:00:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_m4	draw_make_matrix_m4_x(t_v4d pos, double rad, t_v4d scale)
{
	const double		s = sin(rad);
	const double		c = cos(rad);

	return ((t_m4){
		(t_v4d){scale.x, 0.0, 0.0, 0.0},
		(t_v4d){0.0, c * scale.y, s * scale.y, 0.0},
		(t_v4d){0.0, -s * scale.z, c * scale.z, 0.0},
		(t_v4d){pos.x, pos.y, pos.z, 1.0}
	});
}

t_m4	draw_make_matrix_m4_y(t_v4d pos, double rad, t_v4d scale)
{
	const double		s = sin(rad);
	const double		c = cos(rad);

	return ((t_m4){
		(t_v4d){c * scale.x, 0.0, -s * scale.x, 0.0},
		(t_v4d){0.0, scale.y, 0.0, 0.0},
		(t_v4d){s * scale.z, 0.0, c * scale.z, 0.0},
		(t_v4d){pos.x, pos.y, pos.z, 1.0}
	});
}

t_m4	draw_make_matrix_m4_z(t_v4d pos, double rad, t_v4d scale)
{
	const double		s = sin(rad);
	const double		c = cos(rad);

	return ((t_m4){
		(t_v4d){c * scale.x, -s * scale.y, 0.0, 0.0},
		(t_v4d){s * scale.x, c * scale.y, 0.0, 0.0},
		(t_v4d){0.0, 0.0, scale.z, 0.0},
		(t_v4d){pos.x, pos.y, pos.z, 1.0}
	});
}
