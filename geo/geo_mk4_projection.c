/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_mk4_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 21:54:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 17:44:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_m4	geo_mk4_projection(const t_proj p)
{
	return ((t_m4){
		(t_v4d){
			(p.near * 2.0) / (p.right - p.left),
			0.0,
			(p.right + p.left) / (p.right - p.left),
			0.0},
		(t_v4d){
			0.0,
			(p.near * 2.0) / (p.top - p.bottom),
			(p.top + p.bottom) / (p.top - p.bottom),
			0.0},
		(t_v4d){
			0.0,
			0.0,
			-(p.far + p.near) / (p.far - p.near),
			(-2 * p.far * p.near) / (p.far - p.near)},
		(t_v4d){0.0, 0.0, -1.0, 0.0}
	});
}
