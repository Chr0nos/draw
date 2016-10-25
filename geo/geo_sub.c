/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 18:35:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/25 21:28:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f	geo_subv(t_v3f a, t_v3f b)
{
	return ((t_v3f){a.x - b.x, a.y - b.y, a.z - b.z});
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
