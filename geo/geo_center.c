/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 21:17:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/25 21:38:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f	geo_center_v3(t_v3f *vertex, size_t n)
{
	t_v3f		min;
	t_v3f		max;

	min = vertex[--n];
	max = vertex[n];
	while (n--)
	{
		if (vertex[n].x < min.x)
			min.x = vertex[n].x;
		if (vertex[n].y < min.y)
			min.y = vertex[n].y;
		if (vertex[n].z < min.z)
			min.z = vertex[n].z;
		if (vertex[n].x > max.x)
			max.x = vertex[n].x;
		if (vertex[n].y > max.y)
			max.y = vertex[n].y;
		if (vertex[n].z > max.z)
			max.z = vertex[n].z;
	}
	return ((t_v3f){
		min.x + (max.x - min.x) * 0.5f,
		min.y + (max.y - min.y) * 0.5f,
		min.z + (max.z - min.z) * 0.5f
	});
}
