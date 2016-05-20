/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_getgeometry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 23:45:56 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 23:48:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_point		draw_getgeometry(SDL_Window *window)
{
	t_point	px;

	SDL_GetWindowSize(window, &px.x, &px.y);
	return (px);
}
