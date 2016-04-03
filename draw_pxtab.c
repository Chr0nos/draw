/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pxtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:42:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 18:57:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <string.h>

void	draw_pxtab(SDL_Renderer *r, t_point *tab, size_t size,
	unsigned int color)
{
	size_t	p;

	draw_setcolor(r, color);
	p = 0;
	while (p < size)
	{
		SDL_RenderDrawPoint(r, tab[p].x, tab[p].y);
		p++;
	}
}
