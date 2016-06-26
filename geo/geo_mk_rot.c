/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mk_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 00:49:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/26 16:26:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include <math.h>

t_matrix	geo_mk_rot_x(double rad)
{
	t_matrix		m;
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	m.x = geo_mkv(1.0, 0.0f, 0.0f);
	m.y = geo_mkv(0.0f, c, s);
	m.z = geo_mkv(0.0f, -s, c);
	m.offset = geo_mkv(0.0f, 0.0f, 0.0f);
	return (m);
}

t_matrix	geo_mk_rot_y(double rad)
{
	t_matrix		m;
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	m.x = geo_mkv(c, 0.0f, -s);
	m.y = geo_mkv(0.0f, 1.0f, 0.0f);
	m.z = geo_mkv(s, 0.0f, c);
	m.offset = geo_mkv(0.0f, 0.0f, 0.0f);
	return (m);
}

t_matrix	geo_mk_rot_z(double rad)
{
	t_matrix		m;
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	m.x = geo_mkv(c, -s, 0.0f);
	m.y = geo_mkv(s, c, 0.0f);
	m.z = geo_mkv(0.0f, 0.0f, 1.0f);
	m.offset = geo_mkv(0.0f, 0.0f, 0.0f);
	return (m);
}
