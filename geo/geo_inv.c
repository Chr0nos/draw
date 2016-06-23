/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_invv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:09:03 by alhote            #+#    #+#             */
/*   Updated: 2016/06/08 18:38:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_vector	geo_invv(t_vector a)
{
	return ((t_vector){-a.x, -a.y, -a.z});
}

t_v4d		geo_invv4(t_v4d v)
{
	return ((t_v4d){-v.x, -v.y, -v.y, -v.w});
}

t_v4f		geo_invv4f(t_v4f v)
{
	return ((t_v4f){-v.x, -v.y, -v.y, -v.w});
}
