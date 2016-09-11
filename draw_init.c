/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 02:46:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/11 21:07:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

int			draw_init_openglcontext(t_draw *d)
{
	d->glcontext = SDL_GL_CreateContext(d->win);
	if (!d->glcontext)
	{
		ft_putendl(SDL_GetError());
		return (-1);
	}
	ft_putendl("libdraw: opengl context ok");
	return (0);
}

int			draw_init(t_draw *d, t_v2i geometry, const char *title)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putendl("error: failed to init sdl");
		return (-1);
	}
	d->geometry = geometry;
	d->win = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		geometry.x, geometry.y,
		SDL_WINDOW_RESIZABLE);
	if (!d->win)
	{
		ft_putendl("error: failed to init sdl window");
		return (-2);
	}
	d->render = NULL;
	d->screen = NULL;
	d->screen_tex = NULL;
	d->glcontext = NULL;
	return (0);
}
