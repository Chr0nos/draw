/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_multiply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:21:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/31 01:47:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vector	draw_matrix_multiply(t_vector point, const t_matrix *t)
{
	return (draw_make_vector(
			(t->x.x * point.x) + (t->x.y * point.y) + (t->x.z * point.z),
			(t->y.x * point.x) + (t->y.y * point.y) + (t->y.z * point.z),
			(t->z.x * point.x) + (t->z.y * point.y) + (t->z.z * point.z)));
}

t_v4f		draw_matrix_multiply_m4(t_v4f pt, const t_m4 *m)
{
	return ((t_v4f){
		(m->x.x * pt.x) + (m->x.y * pt.y) + (m->x.z * pt.z) + (m->x.w * pt.w),
		(m->y.x * pt.x) + (m->y.y * pt.y) + (m->y.z * pt.z) + (m->y.w * pt.w),
		(m->z.x * pt.x) + (m->z.y * pt.y) + (m->z.z * pt.z) + (m->z.w * pt.w),
		(m->w.x * pt.x) + (m->w.y * pt.y) + (m->w.z * pt.z) + (m->w.w * pt.w)
	});
}
