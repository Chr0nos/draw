/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/15 17:08:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "geo.h"

unsigned int		draw_suv(SDL_Surface *surface, t_v2f uv)
{
	const register int		posy = (int)(surface->h * uv.y);
	const register int		posx = (int)(surface->w * uv.x);

	if ((posy >= surface->h) || (posy < 0) ||
		(posx >= surface->w) || (posx < 0))
		return (*(unsigned int *)surface->pixels);
	return (((unsigned int*)surface->pixels)[posy * surface->w + posx]);
}

/*
** uv MUST be bettween 0 and 1, this function will NOT clamp values
** step = how many UV between 2 pixels
** color_a = the current pixel in the uv texture (not smooth at all)
** color = the color of the near pixel to interpolate
**    it has a x and y for each near sides
** lerp_pc = a number range(0.0 - 0.5) to know the value of the degrade to to
**    lerp.z is for the global interpolation bewtween lerp.x and lerp.y
**   with between color_a and color_b (0.0 = color_a)
** pxuv = fractional part of the position:
** - the idea is to considerate the center of the current pixel as 0, 0 uv
**   instead of 0.5, 0.5, then look wich value is under 0 to know wich pixel
**   will be used for the color_lerp
** ----
** function logic:
**    r = fractional_part(uv / texture_size) - 0.5f
**    if (r < 0.0f) then use the pixel left or down of the current
**    else use the pixel right or up the current
**    do a lerp bewtween the 2 selected pixels (color.x and color.y)
** ----
** for debug purpose:
** color.x = 0xff0000;
** color.y = 0x0000ff;
*/

static inline float	clamp(float x)
{
	return (geo_clamp(x, 0.0f, 1.0f));
}

unsigned int		draw_suv_smooth(SDL_Surface *surface, t_v2f uv)
{
	const t_v2f			step = (t_v2f){1.0f / surface->w, 1.0f / surface->h};
	t_v2f				pxuv;
	const unsigned int	color_a = draw_suv(surface, uv);
	t_v3ui				color;
	t_v3f				lerp_pc;

	pxuv = (t_v2f){
		(geo_fract(uv.x * surface->w) - 0.5f) * 2.0f,
		(geo_fract(uv.y * surface->h) - 0.5f) * 2.0f
	};
	color.x = draw_suv(surface,
		(t_v2f){clamp(uv.x + ((pxuv.x > 0.0f) ? step.x : -step.x)), uv.y});
	color.y = draw_suv(surface,
		(t_v2f){uv.x, clamp(uv.y + ((pxuv.x > 0.0f) ? step.y : -step.y))});
	pxuv = (t_v2f){ABS(pxuv.x), ABS(pxuv.y)};
	lerp_pc.x = 1.0f / pxuv.x;
	lerp_pc.y = 1.0f / pxuv.y;
	lerp_pc.z = (pxuv.x < pxuv.y) ? pxuv.y : pxuv.x;
	color.x = draw_color_lerp(color_a, color.x,
		geo_clamp(lerp_pc.x, 0.0f, 0.5f));
	color.y = draw_color_lerp(color_a, color.y,
		geo_clamp(lerp_pc.y, 0.0f, 0.5f));
	color.z = draw_color_lerp(color.x, color.y, lerp_pc.z);
	return (color.z | (color_a & 0xff000000));
}
