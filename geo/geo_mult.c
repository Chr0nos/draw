/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:51:26 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 14:21:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f		geo_multv(t_v3f a, t_v3f b)
{
	return ((t_v3f){a.x * b.x, a.y * b.y, a.z * b.z});
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

t_v2f		geo_v2f_mult(t_v2f px, const float x)
{
	return ((t_v2f){px.x * x, px.y * x});
}
