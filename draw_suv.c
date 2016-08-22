/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/22 18:16:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "geo.h"
#include <math.h>

unsigned int	draw_suv(SDL_Surface *surface, t_v2f pos)
{
	const t_v2i	px = (t_v2i){
		(int)((float)surface->w * pos.x),
		(int)((float)surface->h * pos.y)};

	return (((unsigned int*)surface->pixels)[px.y * surface->w + px.x]);
}

static int		geo_ceilf(float x)
{
	const float		f = ceilf(x);

	return ((int)f);
}

unsigned int	draw_suv_smooth(SDL_Surface *surface, t_v2f uv)
{
	t_v2f			px;
	t_v2f			pc;
	float			lerp_pc;
	unsigned int	color_a;
	unsigned int	color_b;

	px = (t_v2f){
		(float)surface->w * uv.x,
		(float)surface->h * uv.y
	};
	pc.x = (px.x - floorf(px.x));
	pc.y = (px.y - floorf(px.y));
	color_a = ((unsigned int *)surface->pixels)[(int)px.y * surface->w + (int)px.x];
	color_b = ((unsigned int *)surface->pixels)[geo_ceilf(px.y) * surface->w + geo_ceilf(px.x)];
	lerp_pc = (pc.x > pc.y) ? pc.x : pc.y;
	return (draw_color_lerp(color_a, color_b, lerp_pc * 1.5f) | (color_a & 0xff000000));
}
