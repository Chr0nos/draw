/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_perlin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 00:44:15 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/29 16:20:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

/*
** implementation: https://www.shadertoy.com/view/XtXXD8
*/

static float		r(t_v2f n)
{
	return (geo_fract(cosf(geo_dotv2f(n, (t_v2f){36.26f, 73.12f})) * 354.63f));
}

static float		noise(t_v2f n)
{
	t_v2f	fn;
	t_v2f	sn;
	float	h1;
	float	h2;

	fn = (t_v2f){floorf(n.x), floorf(n.y)};
	sn = geo_smoothstep(
			(t_v2f){0.0f, 0.0f},
			(t_v2f){1.0f, 1.0f},
			geo_fract_v2f(n));
	h1 = geo_mix(r(fn), r(geo_addv2f(
			(t_v2f){fn.x, fn.y},
			(t_v2f){1.0f, 0.0f})), sn.x);
	h2 = geo_mix(r((t_v2f){fn.x, fn.y + 1.0f}),
		r((t_v2f){fn.x + 1.0f, fn.y + 1.0f}), sn.x);
	return (geo_mix(h1, h2, sn.y));
}

float				geo_perlin(t_v2f px)
{
	float	total;

	total = noise(geo_v2f_mult(geo_v2f_div(px, 32.0f), 0.5875f)) +
		noise(geo_v2f_div(px, 16.0f)) * 0.2f +
		noise(geo_v2f_mult(px, 0.125f)) * 0.1f +
		noise(geo_v2f_div(px, 4.0f)) * 0.05f +
		noise(geo_v2f_div(px, 2.0f)) * 0.025f +
		noise(px) * 0.0125f;
	return (total);
}
