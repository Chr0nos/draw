/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:02:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/23 19:27:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include <math.h>

t_matrix	geo_mk_rotx(t_v3f pos, float rad, t_v3f scale)
{
	t_matrix		m;
	const float		s = sinf(rad);
	const float		c = cosf(rad);

	m.x = geo_mkv(scale.x, 0.0f, 0.0f);
	m.y = geo_mkv(0.0f, c * scale.y, s * scale.z);
	m.z = geo_mkv(0.0f, -s * scale.y, c * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	geo_mk_roty(t_v3f pos, float rad, t_v3f scale)
{
	t_matrix		m;
	const float		s = sinf(rad);
	const float		c = cosf(rad);

	m.x = geo_mkv(c * scale.x, 0.0f, -s * scale.z);
	m.y = geo_mkv(0.0f, scale.y, 0.0f);
	m.z = geo_mkv(s * scale.x, 0.0f, c * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	geo_mk_rotz(t_v3f pos, float rad, t_v3f scale)
{
	t_matrix		m;
	const float		s = sinf(rad);
	const float		c = cosf(rad);

	m.x = geo_mkv(c * scale.x, -s * scale.y, 0.0f);
	m.y = geo_mkv(s * scale.x, c * scale.y, 0.0f);
	m.z = geo_mkv(0.0f, 0.0f, scale.z);
	m.offset = pos;
	return (m);
}
