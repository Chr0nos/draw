/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/23 21:41:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "geo.h"

unsigned int	draw_suv(SDL_Surface *surface, t_v2f uv)
{
	return (((unsigned int*)surface->pixels)[(int)(surface->h * uv.y) *
		surface->w + (int)(surface->w * uv.x)]);
}

/*
** uv MUST be bettween 0 and 1, this function will NOT clamp values
** step = how many UV between 2 pixels
** color_a = the current pixel in the uv texture (not smooth at all)
** color_b = the color of the near pixel to interpolate
** lerp_pc = a number range(0.0 - 0.5) to know the value of the degrade to to
**   with between color_a and color_b (0.0 = color_a)
** frac = fractional part of the position:
** - the idea is to considerate the center of the current pixel as 0, 0 uv
**   instead of 0.5, 0.5, then look wich value is under 0 to know wich pixel
**   will be used for the color_lerp
** ----
** function logic:
** ... who knows.... i dont even know what i'm doing !!!
*/

#include <stdio.h>

static inline float	clamp(float x)
{
	return (geo_clamp(x, 0.0f, 1.0f));
}

unsigned int	draw_suv_smooth(SDL_Surface *surface, t_v2f uv)
{
	const t_v2f			step = (t_v2f){1.0f / surface->w, 1.0f / surface->h};
	t_v2f				pxuv;
	const unsigned int	color_a = draw_suv(surface, uv);
	t_v3ui				color;
	t_v3f				lerp_pc;

	pxuv = (t_v2f){
		geo_fract(uv.x * surface->w) - 0.5f,
		geo_fract(uv.y * surface->h) - 0.5f
	};
	color.x = draw_suv(surface, (t_v2f){clamp(uv.x + ((pxuv.x > 0.0f) ? step.x : -step.x)), uv.y});
	color.y = draw_suv(surface, (t_v2f){uv.x, clamp(uv.y + ((pxuv.x > 0.0f) ? step.y : -step.y))});
	color.x = 0xff0000;
	color.y = 0x0000ff;
//	printf("%f %f lerp: %f\n", (double)pxuv.x, (double)pxuv.y, (double)lerp_pc.x);
	lerp_pc.x = ABS(pxuv.x);
	lerp_pc.y = ABS(pxuv.y);
	lerp_pc.z = (lerp_pc.x + lerp_pc.y) * 0.5f;
	color.z = draw_color_lerp(draw_color_lerp(color_a, color.x, lerp_pc.x),
		color.y, lerp_pc.z);
	return (color.z | (color_a & 0xff000000));
}
