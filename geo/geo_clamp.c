/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_clamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:26:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/06 17:26:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

float		geo_clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	return ((x > max) ? max : x);
}
