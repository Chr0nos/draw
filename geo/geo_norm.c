/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 18:32:19 by alhote            #+#    #+#             */
/*   Updated: 2017/06/05 16:58:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f			geo_normv(const t_v3f v)
{
	float		size;

	if ((size = v.x * v.x + v.y * v.y + v.z * v.z) == 1.0f)
		return (v);
	size = 1.0f / sqrtf(size);
	return ((t_v3f){
		.x = v.x * size,
		.y = v.y * size,
		.z = v.z * size
	});
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
