/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_quat_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:12:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/14 19:28:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include "quaternion.h"

/*
** rot = in radians
** axis = the axis i am rotate around
** note: axis MUST be normalized
*/

t_quaternion		geo_quat_rot(t_v3d axis, double rot)
{
	double			sa;

	rot *= 0.5;
	sa = sin(rot);
	return ((t_quaternion){
			.r = cos(rot),
			.i = axis.x * sa,
			.j = axis.y * sa,
			.k = axis.z * sa});
}
