/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/23 14:05:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "geo.h"

unsigned int	draw_suv(SDL_Surface *surface, t_v2f uv)
{
	return (((unsigned int*)surface->pixels)[(int)(surface->h * uv.y) *
		surface->w + (int)(surface->w * uv.x)]);
}

//#include <stdio.h>
unsigned int	draw_suv_smooth(SDL_Surface *surface, t_v2f uv)
{
	const t_v2f			unit = (t_v2f){1.0f / surface->w, 1.0f / surface->h};
	t_v2f				frac;
	const unsigned int	color_a = draw_suv(surface, uv);
	unsigned int		color_b;
	float				lerp_pc;

	frac = (t_v2f){
		(1.0f / uv.x * unit.x),
		(1.0f / uv.y * unit.y)
	};
	uv = (t_v2f)
	{
		geo_clamp(uv.x + ((frac.x < unit.x * 0.5f) ? -unit.x : unit.x), 0.0f, 1.0f),
		geo_clamp(uv.y + ((frac.y < unit.y * 0.5f) ? -unit.y : unit.y), 0.0f, 1.0f)
	};
	lerp_pc = (uv.x > uv.y) ? uv.x : uv.y;
	color_b = draw_suv(surface, uv);
	//color_b = 0xff0000;
	//printf("%f %f lerp: %f\n", (double)frac.x, (double)frac.y, (double)lerp_pc);
	return (draw_color_lerp(color_a, color_b, geo_clamp(lerp_pc, 0.0f, 0.5f)));
}
