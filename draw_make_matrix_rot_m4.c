/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_rot_m4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:08:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/01 18:02:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_m4	draw_make_matrix_m4_x(t_v4f pos, double rad, t_v4f scale)
{
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	return ((t_m4){
		(t_v4f){scale.x, 0.0, 0.0, scale.x},
		(t_v4f){0.0, c * scale.y, s * scale.z, scale.y},
		(t_v4f){0.0, -s * scale.y, c * scale.z, scale.z},
		(t_v4f){pos.x, pos.y, pos.z, scale.w}
	});
}

t_m4	draw_make_matrix_m4_y(t_v4f pos, double rad, t_v4f scale)
{
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	return ((t_m4){
		(t_v4f){c, 0.0, -s * scale.y, scale.x},
		(t_v4f){0.0, scale.y, 0.0, scale.y},
		(t_v4f){s * scale.x, 0.0, c * scale.z, scale.z},
		(t_v4f){pos.x, pos.y, pos.z, scale.w}
	});
}

t_m4	draw_make_matrix_m4_z(t_v4f pos, double rad, t_v4f scale)
{
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	return ((t_m4){
		(t_v4f){c * scale.x, -s * scale.y, 0.0, scale.x},
		(t_v4f){s * scale.x, c * scale.y, 0.0, scale.y},
		(t_v4f){0.0, 0.0, scale.z, scale.z},
		(t_v4f){pos.x, pos.y, pos.z, scale.w}
	});
}
