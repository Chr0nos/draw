/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_fract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:00:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/23 14:01:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include <math.h>

float	geo_fract(float x)
{
	return (x - floorf(x));
}

t_v2f	geo_fract_v2f(t_v2f v)
{
	return ((t_v2f){geo_fract(v.x), geo_fract(v.y)});
}
