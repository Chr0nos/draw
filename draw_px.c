/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 18:55:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_setcolor(SDL_Renderer *r, unsigned int color)
{
	SDL_SetRenderDrawColor(r,
		(color & 0xff0000) >> 16,
		(color & 0xff00) >> 8,
	 	color & 0xff,
		255 - ((color & 0xff000000) >> 24));
}

void	draw_px(SDL_Renderer *r, const t_point px, unsigned int color)
{
	draw_setcolor(r, color);
	SDL_RenderDrawPoint(r, px.x, px.y);
}
