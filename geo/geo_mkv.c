/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mkv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:09:34 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 14:21:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f		geo_mkv(float x, float y, float z)
{
	t_v3f	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_v4d		geo_dtov4d(double x)
{
	return ((t_v4d){x, x, x, 1.0});
}
