/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:59:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/26 16:26:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

double		geo_distv4(const t_v4d a, const t_v4d b)
{
	const double	dx = (b.x - a.x) * (b.x - a.x);
	const double	dy = (b.y - a.y) * (b.y - a.y);
	const double	dz = (b.z - a.z) * (b.z - a.z);

	return (sqrt(dx + dy + dz));
}
