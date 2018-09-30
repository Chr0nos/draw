/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 13:51:58 by alhote            #+#    #+#             */
/*   Updated: 2018/09/30 18:00:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v4d		geo_crossv4(t_v4d a, t_v4d b)
{
	return ((t_v4d){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		a.w * b.w
	});
}

t_v3f		geo_cross(t_v3f a, t_v3f b)
{
	return ((t_v3f){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x});
}
