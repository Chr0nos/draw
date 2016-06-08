/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:51:26 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/08 18:38:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vector	draw_vector_mult(t_vector a, t_vector b)
{
	return ((t_vector){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_v4d		draw_v4d_mult(t_v4d a, t_v4d b)
{
	return ((t_v4d){
		a.x * b.x,
		a.y * b.y,
		a.z * b.z,
		a.w * b.w
	});
}

t_v4f		draw_v4f_mult(t_v4f a, t_v4f b)
{
	return ((t_v4f){
		a.x * b.x,
		a.y * b.y,
		a.z * b.z,
		a.w * b.w
	});
}
