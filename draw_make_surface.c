/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 19:47:06 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:18:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

SDL_Surface		*draw_make_surface(const t_v2i size)
{
	return (SDL_CreateRGBSurface(0,
		size.x, size.y, 32, 0xff0000, 0x00ff00, 0x0000ff, 0xff000000));
}
