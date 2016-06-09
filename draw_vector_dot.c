/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_dot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:14:38 by alhote            #+#    #+#             */
/*   Updated: 2016/06/09 22:32:51 by qloubier         ###   ########.fr       */
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
			a.z * b.z);
}

float	draw_v4f_dot(t_v4f a, t_v4f b)
{
	return (a.x * b.x +
			a.y * b.y +
			a.z * b.z);
}
