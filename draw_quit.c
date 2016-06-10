/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 03:27:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/10 03:29:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_quit(t_draw *d)
{
	if (d->glcontext)
		SDL_GL_DeleteContext(d->glcontext);
	if (d->render)
		SDL_RenderClear(d->render);
	if (d->win)
		SDL_DestroyWindow(d->win);
	SDL_Quit();
}
