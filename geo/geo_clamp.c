/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_clamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:26:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/14 17:59:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

float		geo_clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	return ((x > max) ? max : x);
}

t_v2f		geo_clamp_v2f(t_v2f values, const t_v2f min, const t_v2f max)
{
	if (values.x < min.x)
		values.x = min.x;
	if (values.y < min.y)
		values.y = min.y;
	return ((t_v2f){
		(values.x > max.x) ? max.x : values.x,
		(values.y > max.y) ? max.y : values.y});
}
