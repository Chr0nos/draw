/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 18:32:19 by alhote            #+#    #+#             */
/*   Updated: 2016/06/09 17:27:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vector		draw_vector_norm(t_vector v)
{
	float	size;

	size = sqrtf(powf(v.x, 2.0) + powf(v.y, 2.0) + powf(v.z, 2.0));
	return ((t_vector){v.x / size, v.y / size, v.z / size});
}

t_v4f			draw_v4f_norm(t_v4f v)
{
	const float	n = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

	return ((t_v4f){
		v.x / n,
		v.y / n,
		v.z / n,
		v.w
	});
}

t_v4d			draw_v4d_norm(t_v4d v)
{
	const double	n = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	return ((t_v4d){
		v.x / n,
		v.y / n,
		v.z / n,
		v.w
	});
}
