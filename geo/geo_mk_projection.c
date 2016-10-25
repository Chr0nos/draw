/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mk_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:04:58 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/23 22:52:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_matrix	geo_mk_perspective(t_perspective s, t_v3f c)
{
	t_matrix		m;
	float			frustumdepth;
	float			oneoverdepth;

	frustumdepth = s.fardist - s.neardist;
	oneoverdepth = 1 / frustumdepth;
	m.y = geo_mkv(0.0f, 1 / tanf(0.5f * s.fov), 0.0f);
	m.x = geo_mkv((s.lefthanded ? 1 : -1) * m.y.y / s.aspect,
		0.0f, 0.0f);
	m.z = geo_mkv(0.0f, 0.0f, s.fardist * oneoverdepth);
	m.offset = geo_mkv(c.x, c.z,
		(-s.fardist * s.neardist) * oneoverdepth);
	return (m);
}

t_matrix	geo_mk_ortho(t_v3f s, t_v3f c)
{
	t_matrix		m;

	m.x = geo_mkv(s.x, 0.0f, 0.0f);
	m.y = geo_mkv(0.0f, 0.0f, s.y);
	m.z = geo_mkv(0.0f, s.z, 0.0f);
	m.offset = geo_mkv(c.x, c.z, c.y);
	return (m);
}

t_matrix	geo_mk_iso(int x, int y, int w, int h)
{
	t_matrix		m;

	m.x = geo_mkv((float)w, 0.0f, 0.0f);
	m.y = geo_mkv(0.0f, (float)h, 0.0f);
	m.z = geo_mkv(0.0f, 0.0f, 1.0f);
	m.offset = geo_mkv(x, y, 0.0f);
	return (m);
}

t_matrix	geo_mk_identity(void)
{
	t_matrix	m;

	m.x = geo_mkv(1.0, 0.0, 0.0);
	m.y = geo_mkv(0.0, 1.0, 0.0);
	m.z = geo_mkv(0.0, 0.0, 1.0);
	m.offset = geo_mkv(0.0, 0.0, 0.0);
	return (m);
}
