/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_rot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 00:49:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/29 00:56:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_matrix	draw_make_matrix_rot_x(double rad)
{
	t_matrix		m;
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	m.x = draw_make_vector(1.0, 0.0f, 0.0f);
	m.y = draw_make_vector(0.0f, c, s);
	m.z = draw_make_vector(0.0f, -s, c);
	m.offset = draw_make_vector(0.0f, 0.0f, 0.0f);
	return (m);
}

t_matrix	draw_make_matrix_rot_y(double rad)
{
	t_matrix		m;
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	m.x = draw_make_vector(c, 0.0f, -s);
	m.y = draw_make_vector(0.0f, 1.0f, 0.0f);
	m.z = draw_make_vector(s, 0.0f, c);
	m.offset = draw_make_vector(0.0f, 0.0f, 0.0f);
	return (m);
}

t_matrix	draw_make_matrix_rot_z(double rad)
{
	t_matrix		m;
	const float		s = (float)sin(rad);
	const float		c = (float)cos(rad);

	m.x = draw_make_vector(c, -s, 0.0f);
	m.y = draw_make_vector(s, c, 0.0f);
	m.z = draw_make_vector(0.0f, 0.0f, 1.0f);
	m.offset = draw_make_vector(0.0f, 0.0f, 0.0f);
	return (m);
}
