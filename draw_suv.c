/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/03 17:27:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

unsigned int	draw_suv(SDL_Surface *surface, t_v2f pos)
{
	const t_v2i	px = (t_v2i){
		(int)((float)surface->w * pos.x),
		(int)((float)surface->h * pos.y)};

	return (((unsigned int*)surface->pixels)[px.y * surface->w + px.x]);
}
