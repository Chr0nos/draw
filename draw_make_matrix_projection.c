/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_projection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:04:58 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/30 21:43:26 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_matrix	draw_make_matrix_ortho(t_vector s, t_vector c)
{
	t_matrix		m;

	m.x = draw_make_vector(s.x, 0.0f, 0.0f);
	m.y = draw_make_vector(0.0f, 0.0f, s.y);
	m.z = draw_make_vector(0.0f, s.z, 0.0f);
	m.offset = draw_make_vector(c.x, c.z, c.y);
	return (m);
}

t_matrix	draw_make_matrix_iso(int x, int y, int w, int h)
{
	t_matrix		m;

	m.x = draw_make_vector((float)w, 0.0f, 0.0f);
	m.y = draw_make_vector(0.0f, (float)h, 0.0f);
	m.z = draw_make_vector(0.0f, 0.0f, 1.0f);
	m.offset = draw_make_vector(x, y, 0.0f);
	return (m);
}

t_matrix	draw_make_matrix_identity(void)
{
	t_matrix	m;

	m.x = draw_make_vector(1.0, 0.0, 0.0);
	m.y = draw_make_vector(0.0, 1.0, 0.0);
	m.z = draw_make_vector(0.0, 0.0, 1.0);
	m.offset = draw_make_vector(0.0, 0.0, 0.0);
	return (m);
}
