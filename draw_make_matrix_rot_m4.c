/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_rot_m4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:08:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/01 16:43:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_m4	draw_make_matrix_rot_m4_x(double rad)
{
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	return ((t_m4){
		(t_v4f){1.0, 0.0, 0.0, 0.0},
		(t_v4f){0.0, c, s, 0.0},
		(t_v4f){0.0, -s, c, 0.0},
		(t_v4f){0.0, 0.0, 0.0, 0.0}
	});
}

t_m4	draw_make_matrix_rot_m4_y(double rad)
{
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	return ((t_m4){
		(t_v4f){c, 0.0, -s, 0.0},
		(t_v4f){0.0, 1.0, 0.0, 0.0},
		(t_v4f){s, 0.0, c, 0.0},
		(t_v4f){0.0, 0.0, 0.0, 0.0}
	});
}

t_m4	draw_make_matrix_rot_m4_z(double rad)
{
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	return ((t_m4){
		(t_v4f){c, -s, 0.0, 0.0},
		(t_v4f){s, c, 0.0, 0.0},
		(t_v4f){0.0, 0.0, 1.0, 0.0},
		(t_v4f){0.0, 0.0, 0.0, 0.0}
	});
}
