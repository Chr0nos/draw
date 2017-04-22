/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mk4_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 01:53:28 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/22 17:40:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_m4	geo_mk4_identity(void)
{
	return ((t_m4) {
		(t_v4d){1.0, 0.0, 0.0, 0.0},
		(t_v4d){0.0, 1.0, 0.0, 0.0},
		(t_v4d){0.0, 0.0, 1.0, 0.0},
		(t_v4d){0.0, 0.0, 0.0, 1.0}
	});
}

t_m4	geo_mk4_iso(int x, int y, int w, int h)
{
	return ((t_m4) {
		(t_v4d){(double)w, 0.0, 0.0, 0.0},
		(t_v4d){0.0, (double)h, 0.0, 0.0},
		(t_v4d){0.0, 0.0, 1.0, 0.0},
		(t_v4d){(double)x, (double)y, 0.0, 0.0}
	});
}

t_m4	geo_mk4_ortho(const t_v4d s, const t_v4d c)
{
	return ((t_m4){
		(t_v4d){s.x, 0.0, 0.0, c.x},
		(t_v4d){0.0, 0.0, s.y, c.y},
		(t_v4d){0.0, s.z, 0.0, c.z},
		(t_v4d){0.0, 0.0, 0.0, s.w}
	});
}

t_m4f	geo_mk4_tof(const t_m4 m)
{
	return ((t_m4f){
		.x = (t_v4f){(float)m.x.x, (float)m.x.y, (float)m.x.z, (float)m.x.w},
		.y = (t_v4f){(float)m.y.x, (float)m.y.y, (float)m.y.z, (float)m.y.w},
		.z = (t_v4f){(float)m.z.x, (float)m.z.y, (float)m.z.z, (float)m.z.w},
		.w = (t_v4f){(float)m.w.x, (float)m.w.y, (float)m.w.z, (float)m.w.w}
	});
}
