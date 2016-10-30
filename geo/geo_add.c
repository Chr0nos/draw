/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 01:16:51 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 14:20:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f		geo_addv(t_v3f a, t_v3f b)
{
	return ((t_v3f){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_v4f		geo_addv4f(t_v4f a, t_v4f b)
{
	return ((t_v4f){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_v4d		geo_addv4(t_v4d a, t_v4d b)
{
	return ((t_v4d){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_v2f		geo_addv2f(t_v2f a, t_v2f b)
{
	return ((t_v2f){a.x + b.x, a.y + b.y});
}
