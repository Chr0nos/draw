/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:08:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/23 22:10:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f	geo_trans(t_v3f v, const t_matrix *m)
{
	v = geo_apply(v, m);
	v.x += m->offset.x;
	v.y += m->offset.y;
	v.x += m->offset.z;
	return (v);
}

t_v4d		geo_m4trans(t_v4d v, const t_m4 *m)
{
	v = geo_apply_m4(v, m);
	return ((t_v4d){
		v.x + m->w.x * m->w.w * v.w,
		v.y + m->w.y * m->w.w * v.w,
		v.z + m->w.z * m->w.w * v.w,
		v.w * m->w.w
	});
}
