/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 18:35:41 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/08 15:02:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f		geo_subv3(t_v3f a, t_v3f b)
{
	return ((t_v3f){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_v3i		geo_subv3i(const t_v3i a, const t_v3i b)
{
	return ((t_v3i){
			.x = a.x - b.x,
			.y = a.y - b.y,
			.z = a.z - b.z
		});
}

t_v2f		geo_subv2f(const t_v2f a, const t_v2f b)
{
	return ((t_v2f){
		.x = a.x - b.x,
		.y = a.y - b.y		
	});
}

t_v4d		geo_subv4(t_v4d a, t_v4d b)
{
	return ((t_v4d){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w
	});
}

t_v4f		geo_subv4f(t_v4f a, t_v4f b)
{
	return ((t_v4f){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w
	});
}
