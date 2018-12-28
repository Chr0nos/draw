/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_quat_from_rot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:23:04 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/31 22:40:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include "quaternion.h"

/*
** return a fresh quaternion from differents rotations in radians
*/

t_quaternion			geo_quat_from_rot(const t_v3d rotations)
{
	t_quaternion		q;

	q = geo_quat_rot((t_v3d){1.0, 0.0, 0.0}, rotations.x);
	q = geo_quat_mult(q, geo_quat_rot((t_v3d){0.0, 1.0, 0.0}, rotations.y));
	q = geo_quat_mult(q, geo_quat_rot((t_v3d){0.0, 0.0, 1.0}, rotations.z));
	return (q);
}
