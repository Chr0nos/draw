/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:08:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/09 01:34:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vector	draw_vector_transform(t_vector v, const t_matrix *m)
{
	v = draw_matrix_multiply(v, m);
	v.x += m->offset.x;
	v.y += m->offset.y;
	v.x += m->offset.z;
	return (v);
}

t_v4d		draw_vector_transform_m4(t_v4d v, const t_m4 *m)
{
	v = draw_matrix_multiply_m4(v, m);
	return ((t_v4d){
		v.x + m->w.x * m->w.w * v.w,
		v.y + m->w.y * m->w.w * v.w,
		v.z + m->w.z * m->w.w * v.w,
		v.w * m->w.w
	});
}
