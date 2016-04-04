/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsdl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 03:01:09 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 03:03:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWSDL_H
# define DRAWSDL_H
# include "tpoint.h"
# include <SDL2/SDL.h>

typedef struct		s_drawsdl
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Event		events;
	SDL_Surface		*screen;
	t_point			geometry;
	unsigned int	color;
}					t_draw;

#endif
