/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mk4_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:08:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/26 16:26:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include <math.h>

t_m4	geo_mk4_rotx(t_v4d pos, double rad, t_v4d scale)
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

t_m4	geo_mk4_roty(t_v4d pos, double rad, t_v4d scale)
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

t_m4	geo_mk4_rotz(t_v4d pos, double rad, t_v4d scale)
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

t_m4	geo_mk4_euler(t_v4d euler, t_v4d pos, t_v4d scale)
{
	const t_v4d		s = (t_v4d){sin(euler.x), sin(euler.y), sin(euler.z), 0.0};
	const t_v4d		c = (t_v4d){cos(euler.x), cos(euler.y), cos(euler.z), 0.0};

	return ((t_m4){
			(t_v4d){(c.x * c.z - s.x * c.y * s.z) * scale.x,
				(s.x * c.z + c.x * c.y * s.z) * scale.x,
				(s.y * s.z) * scale.x,
				0.0},
			(t_v4d){(-c.x * s.z - s.x * c.y * c.z) * scale.y,
				(-s.x * s.z + c.x * c.y * c.z) * scale.y,
				(s.y * s.z) * scale.y,
				0.0},
			(t_v4d){(s.x * s.y) * scale.z,
				(-c.x * s.y) * scale.z,
				c.y * scale.z,
				0.0},
			pos
	});
}

t_m4	geo_mk4_rot(t_v4d axis, double rad, t_v4d pos, t_v4d scale)
{
	const double		s = sin(rad);
	const double		c = cos(rad);
	const double		cl = 1.0 - c;

	return ((t_m4){
		(t_v4d){
			(axis.x * axis.x * cl + c) * scale.x,
			(axis.x * axis.y * cl + axis.z * s) * scale.x,
			(axis.x * axis.z * cl - axis.y * s) * scale.x,
			0.0},
		(t_v4d){
			(axis.x * axis.y * cl - axis.z * s) * scale.y,
			(axis.y * axis.y * cl + c) * scale.y,
			(axis.y * axis.z * cl + axis.x * s) * scale.y,
			0.0},
		(t_v4d){
			(axis.x * axis.z * cl + axis.y * s) * scale.z,
			(axis.y * axis.z * cl - axis.x * s) * scale.z,
			(axis.z * axis.z * cl + c) * scale.z,
			0.0},
		pos
	});
}
