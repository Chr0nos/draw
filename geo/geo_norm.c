/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 18:32:19 by alhote            #+#    #+#             */
/*   Updated: 2016/10/30 14:21:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f			geo_normv(t_v3f v)
{
	float	size;

	size = sqrtf(powf(v.x, 2.0) + powf(v.y, 2.0) + powf(v.z, 2.0));
	return ((t_v3f){v.x / size, v.y / size, v.z / size});
}

t_v4f			geo_normv4f(t_v4f v)
{
	const float	n = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

	return ((t_v4f){
		v.x / n,
		v.y / n,
		v.z / n,
		v.w
	});
}

t_v4d			geo_normv4(t_v4d v)
{
	const double	n = 1.0 / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	return ((t_v4d){
		v.x * n,
		v.y * n,
		v.z * n,
		v.w
	});
}
