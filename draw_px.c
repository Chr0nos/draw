/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/14 15:19:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

inline void		draw_px(t_mlx *x, const t_point *point, const int color)
{
	*(int *)(unsigned long)(x->img->data + (x->img->width * point->y) +
		(point->x * x->img->blocksize)) = color;
}
