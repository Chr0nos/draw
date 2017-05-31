/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_quat_tomatrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:36 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/31 23:02:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include "quaternion.h"
#include "t_v4.h"

t_m4		geo_quat_tomatrix(const t_quaternion q)
{
	return ((t_m4){
		(t_v4d){
			1.0 - 2.0 * (q.j * q.j + q.k * q.k),
			2.0 * (q.i * q.j - q.r * q.k),
			2.0 * (q.r * q.j + q.i * q.k),
			0.0},
		(t_v4d){
			2.0 * (q.r * q.k + q.i * q.j),
			1.0 - 2.0 * (q.i * q.i + q.k * q.k),
			2.0 * (q.j * q.k - q.r * q.i),
			0.0},
		(t_v4d){
			2.0 * (q.i * q.k - q.r * q.j),
			2.0 * (q.r * q.i + q.j * q.k),
			1.0 - 2.0 * (q.i * q.i + q.j * q.j),
			0.0},
		(t_v4d){0.0, 0.0, 0.0, 1.0}
	});
}

t_m4		geo_quat_tomatrix_offset(const t_quaternion q, const t_v4d offset)
{
	const t_m4		m = geo_quat_tomatrix(q);

	return ((t_m4){
		.x = m.x,
		.y = m.y,
		.z = m.z,
		.w = offset
	});
}
