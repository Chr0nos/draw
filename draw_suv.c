/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/23 19:38:32 by snicolet         ###   ########.fr       */
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

unsigned int	draw_suv_smooth(SDL_Surface *surface, t_v2f uv)
{
	const t_v2f			step = (t_v2f){1.0f / surface->w, 1.0f / surface->h};
	t_v2f				pxuv;
	const unsigned int	color_a = draw_suv(surface, uv);
	t_v3ui				color;
	t_v2f				lerp_pc;

	// frac = geo_fract_v2f((t_v2f){
	// 	(unit.x / ((uv.x - (unit.x * 0.5f))) * (unit.x)) * surface->w,
	// 	(unit.y / ((uv.y - (unit.x * 0.5f))) * (unit.y)) * surface->h
	// });
	pxuv = (t_v2f){
		((uv.x * surface->w) - (uv.x * step.x)) * step.x,
		((uv.y * surface->h) - (uv.y * step.y)) * step.y
	};
	// pxuv = (t_v2f){
	// 	(uv.x - (uv.x / step.x * (surface->w / step.x))) * surface->w,
	// 	(uv.y - (uv.y / step.y * (surface->h / step.y))) * surface->h
	// };
	//pxuv = geo_fract_v2f(pxuv);
	uv = (t_v2f)
	{
		geo_clamp(uv.x + ((pxuv.x < 0.0f) ? -step.x : step.x), 0.0f, 1.0f),
		geo_clamp(uv.y + ((pxuv.y < 0.0f) ? -step.y : step.y), 0.0f, 1.0f)
	};
	//lerp_pc = frac.x + frac.y;
	lerp_pc.x = (pxuv.x + pxuv.y) * 0.5f;
	lerp_pc.y = (pxuv.x + pxuv.y) * 0.5f;
	//lerp_pc = (uv.x > uv.y) ? uv.x : uv.y;
	//color_b = draw_suv(surface, uv);
	color.x = 0xff0000;
	color.y = 0x0000ff;
	printf("%f %f lerp: %f\n", (double)pxuv.x, (double)pxuv.y, (double)lerp_pc.x);
	color.z = draw_color_lerp(draw_color_lerp(color_a, color.x, lerp_pc.x),
		color.y, lerp_pc.y);
	return (color.z | (color_a & 0xff000000));
}
