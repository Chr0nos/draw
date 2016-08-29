/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_blitsurface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 19:32:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/29 16:23:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		draw_blitsurface(SDL_Surface *dest, SDL_Surface *src,
	t_v2i offset)
{
	unsigned int	*dest_pixels;
	unsigned int	*src_pixels;
	t_v2i			px;

	dest_pixels = dest->pixels;
	src_pixels = src->pixels;
	px.x = src->w;
	while (px.x--)
	{
		px.y = src->h;
		while (px.y--)
		{
			dest_pixels[(px.y + offset.y) * dest->w + (px.x + offset.x)] =
				src_pixels[px.y * src->w + px.x];
		}
	}
}

void		draw_blitsurface_dbg_alpha(SDL_Surface *dest, SDL_Surface *src,
	t_v2i offset)
{
	unsigned int	*dest_pixels;
	unsigned int	*src_pixels;
	t_v2i			px;
	unsigned int	color;

	dest_pixels = dest->pixels;
	src_pixels = src->pixels;
	px.x = src->w;
	while (px.x--)
	{
		px.y = src->h;
		while (px.y--)
		{
			color = src_pixels[px.y * src->w + px.x] >> 24;
			color |= (color << 8) | (color << 16);
			dest_pixels[(px.y + offset.y) * dest->w + (px.x + offset.x)] =
				color;
		}
	}
}

void		draw_blitsurface_opc(SDL_Surface *dest, SDL_Surface *src,
	t_v2i offset, const float opc)
{
	unsigned int	*spx;
	unsigned int	*dpx;
	unsigned int	*dest_pixels;
	unsigned int	*src_pixels;
	t_v2i			px;

	if (opc >= 1.0f)
	{
		draw_blitsurface(dest, src, offset);
		return ;
	}
	dest_pixels = dest->pixels;
	src_pixels = src->pixels;
	px.x = src->w;
	while (px.x--)
	{
		px.y = src->h;
		while (px.y--)
		{
			dpx = &dest_pixels[(px.y + offset.y) * dest->w + (px.x + offset.x)];
			spx = &src_pixels[px.y * src->w + px.x];
			*dpx = draw_color_lerp(*dpx, *spx, opc);
		}
	}
}

void		draw_blitsurface_blend(SDL_Surface *dest, SDL_Surface *src,
	t_v2i offset, unsigned int (*blend)(unsigned int, unsigned int))
{
	unsigned int	*dpx;
	unsigned int	*spx;
	unsigned int	*dest_pixels;
	unsigned int	*src_pixels;
	t_v2i			px;

	px.x = src->w;
	dest_pixels = dest->pixels;
	src_pixels = src->pixels;
	while (px.x--)
	{
		px.y = src->h;
		while (px.y--)
		{
			dpx = &dest_pixels[(px.y + offset.y) * dest->w + (px.x + offset.x)];
			spx = &src_pixels[px.y * src->w + px.x];
			*dpx = blend(*dpx, *spx);
		}
	}
}
