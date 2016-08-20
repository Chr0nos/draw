/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_barycentric_coordinates.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 12:25:40 by alhote            #+#    #+#             */
/*   Updated: 2016/08/20 12:50:08 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_v4d		geo_barycentric_coordinates(t_v4d a, t_v4d b, t_v4d c, t_v4d p)
{
	t_v4d	f[3];
	double	area;
	t_v4d	bary;
	t_v4d	n;

	n = geo_crossv4(geo_subv4(b, a), geo_subv4(c, a));
	area = fabs(geo_dotv4(geo_crossv4(geo_subv4(a, b), geo_subv4(c, a)), n));
	f[0] = geo_subv4(a, p);
	f[1] = geo_subv4(b, p);
	f[2] = geo_subv4(c, p);
	bary.x = fabs(geo_dotv4(geo_crossv4(f[1], f[2]), n)) / area;
	bary.y = fabs(geo_dotv4(geo_crossv4(f[2], f[0]), n)) / area;
	bary.z = fabs(geo_dotv4(geo_crossv4(f[0], f[1]), n)) / area;
	bary.w = 0.0;
	return (bary);
}
