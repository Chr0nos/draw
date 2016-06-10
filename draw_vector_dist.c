/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:59:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/10 19:02:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double		draw_v4d_dist(t_v4d a, t_v4d b)
{
	const double	dx = (b.x - a.x) * (b.x - a.x);
	const double	dy = (b.y - a.y) * (b.y - a.y);
	const double	dz = (b.z - a.z) * (b.z - a.z);

	return (sqrt(dx + dy + dz));
}
