/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_multiply_matrix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:33:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/02 17:03:43 by snicolet         ###   ########.fr       */
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

t_m4		draw_matrix_multiply_matrix_m4(t_m4 m1, const t_m4 *m2)
{
	return ((t_m4){
		draw_matrix_multiply_m4(m1.x, m2),
		draw_matrix_multiply_m4(m1.z, m2),
		draw_matrix_multiply_m4(m1.y, m2),
		draw_v4d_add(draw_matrix_multiply_m4(m1.w ,m2), m2->w)
	});
}

t_m4		draw_matrix_multiply_axes_m4(t_v4d axes, t_v4d scale, t_v4d offset)
{
	t_m4			final;
	const t_v4d		o = (t_v4d){0.0, 0.0, 0.0, 0.0};
	const t_m4		mx = draw_make_matrix_m4_x(o, axes.x, scale);
	const t_m4		my = draw_make_matrix_m4_y(o, axes.y, scale);
	const t_m4		mz = draw_make_matrix_m4_z(o, axes.z, scale);

	final = draw_matrix_multiply_matrix_m4(
		draw_matrix_multiply_matrix_m4(mx, &my), &mz);
	final.w = offset;
	return (final);
}
