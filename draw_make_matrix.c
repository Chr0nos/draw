/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:02:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 18:49:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_matrix	draw_make_matrix_x(t_vector pos, float rad, t_vector scale)
{
	t_matrix		m;
	const float		s = sinf(rad);
	const float		c = cosf(rad);

	m.x = draw_make_vector(scale.x, 0.0f, 0.0f);
	m.y = draw_make_vector(0.0f, c * scale.y, s * scale.z);
	m.z = draw_make_vector(0.0f, -s * scale.y, c * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	draw_make_matrix_y(t_vector pos, float rad, t_vector scale)
{
	t_matrix		m;
	const float		s = sinf(rad);
	const float		c = cosf(rad);

	m.x = draw_make_vector(c * scale.x, 0.0f, -s * scale.z);
	m.y = draw_make_vector(0.0f, scale.y, 0.0f);
	m.z = draw_make_vector(s * scale.x, 0.0f, c * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	draw_make_matrix_z(t_vector pos, float rad, t_vector scale)
{
	t_matrix		m;
	const float		s = sinf(rad);
	const float		c = cosf(rad);

	m.x = draw_make_vector(c * scale.x, -s * scale.y, 0.0f);
	m.y = draw_make_vector(s * scale.x, c * scale.y, 0.0f);
	m.z = draw_make_vector(0.0f, 0.0f, scale.z);
	m.offset = pos;
	return (m);
}
