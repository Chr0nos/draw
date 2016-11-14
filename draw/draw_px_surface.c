/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px_surface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:56:52 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:18:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** return the px pixel of the surface,
** surface must be SDL_UnlockSurface before
*/

unsigned int	draw_getpxs(SDL_Surface *surface, t_v2i px)
{
	return (*(unsigned int *)((unsigned long)surface->pixels +
		(unsigned long)(px.y * surface->pitch) +
		(unsigned long)(px.x * surface->format->BytesPerPixel)));
}
