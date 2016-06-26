/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:51:26 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/26 16:26:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_vector	geo_multv(t_vector a, t_vector b)
{
	return ((t_vector){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_v4d		geo_multv4(t_v4d a, t_v4d b)
{
	return ((t_v4d){
		a.x * b.x,
		a.y * b.y,
		a.z * b.z,
		a.w * b.w
	});
}

t_v4f		geo_multv4f(t_v4f a, t_v4f b)
{
	return ((t_v4f){
		a.x * b.x,
		a.y * b.y,
		a.z * b.z,
		a.w * b.w
	});
}
