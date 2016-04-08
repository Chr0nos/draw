/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset_surface.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 01:46:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/08 01:59:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_reset_surface(SDL_Surface *surface, unsigned int color)
{
	unsigned long	blk;
	unsigned long	pixels;
	size_t			size;
	size_t			p;

	blk = (unsigned long)color | (unsigned long)color << 32;
	pixels = (unsigned long)surface->pixels;
	size = (unsigned int)surface->h * (unsigned int)surface->w *
		(unsigned int)surface->format->BytesPerPixel;
	p = 0;
	while (p < size)
	{
		*(unsigned long *)(pixels + p) = blk;
		p += 8;
	}
}
