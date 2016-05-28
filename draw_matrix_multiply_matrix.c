/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_multiply_matrix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:33:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/28 04:03:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_matrix	draw_matrix_multiply_matrix(t_matrix m1, const t_matrix *m2)
{
	m1.x = draw_matrix_multiply(m1.x, m2);
	m1.y = draw_matrix_multiply(m1.y, m2);
	m1.z = draw_matrix_multiply(m1.z, m2);
	m1.offset = draw_matrix_multiply(m1.offset, m2);
	m1.offset.x += m2->offset.x;
	m1.offset.y += m2->offset.y;
	m1.offset.z += m2->offset.z;
	return (m1);
}

t_matrix	draw_matrix_multiply_axes(t_vector axes, t_vector scale,
	t_vector offset)
{
	t_matrix		final;
	const t_vector	o = (t_vector){0.0, 0.0, 0.0};
	const t_matrix	mx = draw_make_matrix_x(o, axes.x, scale);
	const t_matrix	my = draw_make_matrix_y(o, axes.y, scale);
	const t_matrix	mz = draw_make_matrix_z(o, axes.z, scale);

	final = draw_matrix_multiply_matrix(
		draw_matrix_multiply_matrix(mx, &my), &mz);
	final.offset = offset;
	return (final);
}
