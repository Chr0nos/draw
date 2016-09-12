/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_clamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:26:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/12 20:18:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

float		geo_clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	return ((x > max) ? max : x);
}

t_v2f		geo_clamp_v2f(t_v2f values, const float min, const float max)
{
	if (values.x < min)
		values.x = min;
	if (values.y < min)
		values.y = min;
	return ((t_v2f){
		(values.x > max) ? max : values.x,
		(values.y > max) ? max : values.y});
}
