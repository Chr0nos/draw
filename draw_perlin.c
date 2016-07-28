/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perlin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 22:37:39 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/28 23:08:58 by snicolet         ###   ########.fr       */
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
