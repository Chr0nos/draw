/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_inv_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 12:49:35 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/17 19:46:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_m4	geo_inv_m4(const t_m4 m)
{
	double		coef;

	coef = m.x.x * (m.y.y * m.z.z - m.y.z * m.z.y) -
		m.y.x * (m.x.y * m.z.z - m.z.y * m.x.z) +
		m.z.x * (m.x.y * m.y.z - m.y.y * m.x.z);
	coef = 1.0 / coef;
	return ((t_m4){
		(t_v4d){
			((m.y.y * m.z.z) - (m.y.z * m.z.y)) * coef,
			((m.z.y * m.x.z) - (m.x.y * m.z.z)) * coef,
			((m.x.y * m.y.z) - (m.x.z * m.y.y)) * coef,
			0.0},
		(t_v4d){
			((m.z.x * m.y.z) - (m.y.x * m.z.z)) * coef,
			((m.x.x * m.z.z) - (m.z.x * m.x.z)) * coef,
			((m.x.z * m.y.x) - (m.x.x * m.y.z)) * coef,
			0.0},
		(t_v4d){
			((m.y.x * m.z.y) - (m.z.x * m.y.y)) * coef,
			((m.x.y * m.z.x) - (m.x.x * m.z.y)) * coef,
			((m.x.x * m.y.y) - (m.x.y * m.y.x)) * coef,
			0.0},
		geo_invv4(m.w)});
}
