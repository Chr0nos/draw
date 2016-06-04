/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_multiply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:21:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/04 17:59:12 by snicolet         ###   ########.fr       */
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

t_v4d		draw_matrix_multiply_m4(t_v4d pt, const t_m4 *m)
{
	return ((t_v4d){
		(m->x.x * pt.x) + (m->y.x * pt.y) + (m->z.x * pt.z) + (m->w.x * pt.w),
		(m->x.y * pt.x) + (m->y.y * pt.y) + (m->z.y * pt.z) + (m->w.y * pt.w),
		(m->x.z * pt.x) + (m->y.z * pt.y) + (m->z.z * pt.z) + (m->w.z * pt.w),
		(m->x.w * pt.x) + (m->y.w * pt.y) + (m->z.w * pt.z) + (m->w.w * pt.w)
	});
}
