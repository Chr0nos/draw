/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:18:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			draw_setcolor(t_draw *d, unsigned int color)
{
	d->color = color;
}

void			draw_pxi(unsigned int *pixels, const t_v2i px,
	const unsigned int width, const unsigned int color)
{
	pixels[(unsigned int)px.y * width + (unsigned int)px.x] = color;
}

void			draw_px(t_draw *d, const t_v2i px)
{
	const int	bpp = (int)(d->screen->format->BytesPerPixel);
	Uint8		*p;

	p = (Uint8 *)d->screen->pixels + px.y * d->screen->pitch + px.x * bpp;
	if (bpp == 1)
		*p = (Uint8)d->color;
	else if (bpp == 2)
		*(Uint16 *)(unsigned long)p = (Uint16)d->color;
	else if (bpp == 4)
		*(Uint32 *)(unsigned long)p = d->color;
}

void			draw_pxc(t_draw *d, const t_v2i px, unsigned int color)
{
	d->color = color;
	draw_px(d, px);
}

unsigned int	draw_getpx(t_draw *d, t_v2i px)
{
	return (draw_getpxs(d->screen, px));
}
