/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_perlin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 00:44:15 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/28 20:51:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

//fract: partie fractionaire
//implementation: https://www.shadertoy.com/view/XtXXD8

inline static float	fract(float x)
{
	return (x - (int)x);
}

static float		r(t_v2f n)
{
    return (fract(cosf(geo_dotv2f(n, (t_v2f){36.26f, 73.12f})) * 354.63f));
}

static float		mix(float a, float b, float pc)
{
	return (a * (1.0f - pc) + (b * pc));
}

static float		geo_clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	return ((x > max) ? max : x);
}

static t_v2f		smoothstep(t_v2f a, t_v2f b, t_v2f x)
{
	const t_v2f t = {
		geo_clamp((x.x - a.x) / (b.x - a.x), 0.0f, 1.0f),
		geo_clamp((x.y - a.y) / (b.x - a.y), 0.0f, 1.0f),
	};

	return ((t_v2f){t.x * t.x * (3.0f - 2.0f * t.x),
		t.y * t.y * (3.0f - 2.0f * t.y)});
}

static float		noise(t_v2f n)
{
    t_v2f 		fn;
    t_v2f 		sn;
	float		h1;
	float		h2;

	fn = (t_v2f){floorf(n.x), floorf(n.y)};
	sn = smoothstep(
			(t_v2f){0.0f, 0.0f},
			(t_v2f){1.0f, 1.0f},
			fract(n));
    h1 = mix(r(fn), r(geo_addv2f(
			(t_v2f){fn.x, fn.y},
			(t_v2f){1.0f, 0.0f})
		), sn.x);
	h2 = mix(r((t_v2f){fn.x, fn.y + 1.0f}), r((t_v2f){fn.x + 1.0f, fn.y + 1.0f}),
		sn.x);
    return (mix(h1, h2, sn.y));
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
