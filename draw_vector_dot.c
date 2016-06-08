/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_dot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:14:38 by alhote            #+#    #+#             */
/*   Updated: 2016/06/08 18:34:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

float	draw_vector_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	draw_v4d_dot(t_v4d a, t_v4d b)
{
	return (a.x * b.x +
			a.y * b.y +
			a.y * a.y);
}

float	draw_v4f_dot(t_v4f a, t_v4f b)
{
	return (a.x * b.x +
			a.y * b.y +
			a.y * a.y);
}
