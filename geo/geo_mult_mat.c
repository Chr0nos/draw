/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mult_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:33:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 14:22:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_matrix	geo_mult_m3(t_matrix m1, const t_matrix *m2)
{
	m1.x = geo_apply(m1.x, m2);
	m1.y = geo_apply(m1.y, m2);
	m1.z = geo_apply(m1.z, m2);
	m1.offset = geo_apply(m1.offset, m2);
	m1.offset.x += m2->offset.x;
	m1.offset.y += m2->offset.y;
	m1.offset.z += m2->offset.z;
	return (m1);
}

t_matrix	geo_mk_rotxyz(t_v3f axes, t_v3f scale,
	t_v3f offset)
{
	t_matrix		final;
	const t_v3f		o = (t_v3f){0.0, 0.0, 0.0};
	const t_matrix	mx = geo_mk_rotx(o, axes.x, scale);
	const t_matrix	my = geo_mk_roty(o, axes.y, scale);
	const t_matrix	mz = geo_mk_rotz(o, axes.z, scale);

	final = geo_mult_m3(geo_mult_m3(mx, &my), &mz);
	final.offset = offset;
	return (final);
}

t_m4		geo_mult_m4(t_m4 m1, const t_m4 *m2)
{
	t_v4d	w;

	w = m2->w;
	w.w = 0.0;
	return ((t_m4){
		geo_apply_m4(m1.x, m2),
		geo_apply_m4(m1.y, m2),
		geo_apply_m4(m1.z, m2),
		geo_addv4(geo_apply_m4(m1.w, m2), w)
	});
}

t_m4		geo_mk4_rotxyz(t_v4d axes, t_v4d scale, t_v4d offset)
{
	t_m4			final;
	const t_v4d		o = (t_v4d){0.0, 0.0, 0.0, 0.0};
	const t_m4		mx = geo_mk4_rotx(o, axes.x, scale);
	const t_m4		my = geo_mk4_roty(o, axes.y, scale);
	const t_m4		mz = geo_mk4_rotz(o, axes.z, scale);

	final = geo_mult_m4(geo_mult_m4(mx, &my), &mz);
	final.w = offset;
	return (final);
}
