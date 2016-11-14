/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_quat_inv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:32:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/14 19:34:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include "quaternion.h"

t_quaternion	geo_quat_inv(const t_quaternion q)
{
	const double	t = 1 / (q.r * q.r + q.i * q.i + q.j * q.j + q.k * q.k);

	return ((t_quaternion){
		.r = t * q.r,
		.i = -t * q.i,
		.j = -t * q.j,
		.k = -t * q.k});
}
