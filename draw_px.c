/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 22:57:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_setcolor(t_draw *d, unsigned int color)
{
	d->color = color;
	/*
	SDL_SetRenderDrawColor(r,
		(color & 0xff0000) >> 16,
		(color & 0xff00) >> 8,
	 	color & 0xff,
		255 - ((color & 0xff000000) >> 24));
	*/
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
