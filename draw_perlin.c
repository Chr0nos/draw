/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perlin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 22:37:39 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/30 03:18:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static unsigned int		colorf(float x)
{
	unsigned char	b;

	b = (unsigned char)(x * 255.0f);
	return ((unsigned int)(b | (b << 8) | (b << 16)));
}

void					draw_perlin(SDL_Surface *surface)
{
	t_v2i			px;
	unsigned int	*pixels;

	pixels = surface->pixels;
	px.x = surface->w;
	while (px.x--)
	{
		px.y = surface->h;
		while (px.y--)
		{
			pixels[px.y * surface->w + px.x] = colorf(geo_perlin((t_v2f){
				(float)px.x,
				(float)px.y}));
		}
	}
}

static float		draw_perlin_aa_px(t_v2f v)
{
	float			perlin;

	perlin = geo_perlin(v) +
			geo_perlin((t_v2f){v.x + 1.0f, v.y}) +
			geo_perlin((t_v2f){v.x - 1.0f, v.y}) +
			geo_perlin((t_v2f){v.x, v.y - 1.0f}) +
			geo_perlin((t_v2f){v.x, v.y + 1.0f}) +
			geo_perlin((t_v2f){v.x + 1.0f, v.y + 1.0f}) +
			geo_perlin((t_v2f){v.x - 1.0f, v.y + 1.0f}) +
			geo_perlin((t_v2f){v.x + 1.0f, v.y - 1.0f}) +
			geo_perlin((t_v2f){v.x - 1.0f, v.y - 1.0f});
	return (perlin / 9.0f);
}

void				draw_perlin_aa(SDL_Surface *surface)
{
	t_v2i			px;
	unsigned int	*pixels;

	pixels = surface->pixels;
	px.x = surface->w;
	while (px.x--)
	{
		px.y = surface->h;
		while (px.y--)
		{
			pixels[px.y * surface->w + px.x] = colorf(draw_perlin_aa_px((t_v2f){
				(float)px.x,
				(float)px.y}));
		}
	}
}
