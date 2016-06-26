/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:14:38 by alhote            #+#    #+#             */
/*   Updated: 2016/06/26 16:26:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

float	geo_dotv(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	geo_dotv4(t_v4d a, t_v4d b)
{
	return (a.x * b.x +
			a.y * b.y +
			a.z * b.z);
}

float	geo_dotv4f(t_v4f a, t_v4f b)
{
	return (a.x * b.x +
			a.y * b.y +
			a.z * b.z);
}