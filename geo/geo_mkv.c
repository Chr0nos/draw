/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:09:34 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/23 20:20:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f	geo_mkv(float x, float y, float z)
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
