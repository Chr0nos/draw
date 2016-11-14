/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_quat_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:17:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/14 22:39:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include "quaternion.h"

t_quaternion	geo_quat_mult(const t_quaternion a, const t_quaternion b)
{
	return ((t_quaternion){
		.r = a.r * b.r - a.i * b.i - a.j * b.j - a.k * b.k,
		.i = a.r * b.i + b.r * a.i + a.j * b.k - b.j * a.k,
		.j = a.r * b.j + b.r * a.j - a.i * b.k + b.i * a.k,
		.k = a.r * b.k + b.r * a.k + a.i * b.j - b.i * a.j});
}
