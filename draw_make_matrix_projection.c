/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_projection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:04:58 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/30 21:39:22 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_matrix	draw_make_matrix_perspective(t_perspective s, t_vector c)
{
	t_matrix		m;
	float			frustumdepth;
	float			oneoverdepth;

	frustumdepth = s.farDist - s.nearDist;
	oneoverdepth = 1 / s.frustumDepth;
	if (fov <= 0 || aspect == 0)
		return (0);
	m.y = draw_make_vector(0.0f, 1 / tan(0.5f * s.fov), 0.0f);
	m.x = draw_make_vector((s.lefthanded ? 1 : -1) * m.y.y / s.aspect, 0.0f, 0.0f);
	m.z = draw_make_vector(0.0f, 0.0f, s.fardist * s.oneOverDepth);
	m.z.offset = 1;
	m.offset = draw_make_vector(c.x, c.z, (-s.fardist * s.neardist) * s.oneoverDepth);
	m.offset.z = 0;
}
//
    // General form of the Projection Matrix
    //
    // uh = Cot( fov/2 ) == 1/Tan(fov/2)
    // uw / uh = 1/aspect
    //
    //   uw         0       0       0
    //    0        uh       0       0
    //    0         0      f/(f-n)  1
    //    0         0    -fn/(f-n)  0
    //
    // Make result to be identity first


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
