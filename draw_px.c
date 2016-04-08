/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/05 01:31:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_setcolor(t_draw *d, unsigned int color)
{
	d->color = color;
}

void	draw_px(t_draw *d, const t_point px)
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

void	draw_pxc(t_draw *d, const t_point px, unsigned int color)
{
	d->color = color;
	draw_px(d, px);
}

/*
** return the px pixel of the surface,
** surface must be SDL_UnlockSurface before
*/

unsigned int	draw_getpxs(SDL_Surface *surface, t_point px)
{
	//if (surface->format->BytesPerPixel == 4)
		return (*(unsigned int *)((unsigned long)surface->pixels +
			(unsigned long)(px.y * surface->pitch) +
			(unsigned long)(px.x * surface->format->BytesPerPixel)));
	//else
	//	return (0);
}

unsigned int	draw_getpx(t_draw *d, t_point px)
{
	return (draw_getpxs(d->screen, px));
}
