/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_inv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:09:03 by alhote            #+#    #+#             */
/*   Updated: 2016/10/30 14:20:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v3f		geo_invv(t_v3f a)
{
	return ((t_v3f){-a.x, -a.y, -a.z});
}

t_v4d		geo_invv4(t_v4d v)
{
	return ((t_v4d){-v.x, -v.y, -v.y, -v.w});
}

t_v4f		geo_invv4f(t_v4f v)
{
	return ((t_v4f){-v.x, -v.y, -v.y, -v.w});
}
