/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 15:57:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		draw_px(t_mlx *x, const t_point *point, unsigned int color)
{
	*(unsigned int *)(unsigned long)(x->img->data + (x->img->width * point->y) +
		(point->x * x->img->blocksize)) = color;
}

void		draw_px_alpha(t_mlx *x, const t_point *point, unsigned int color)
{
	int				tmp;
	unsigned int	color_origin;
	t_rgb			s;
	t_rgb			*d;

	d = (t_rgb *)&color;
	color_origin = draw_get_px(x, point);
	s = *(t_rgb *)&color_origin;
	tmp = (int)s.r * (255 - d->a) + (d->r * d->a);

	*(unsigned int *)(unsigned long)(x->img->data + (x->img->width * point->y) +
		(point->x * x->img->blocksize)) = color;
}
