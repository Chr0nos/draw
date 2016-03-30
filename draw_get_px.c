/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 22:12:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 15:34:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

unsigned int	draw_get_px(t_mlx *x, const t_point *point)
{
	return (*(unsigned int *)(unsigned long)(x->img->data +
		(x->img->width * point->y) + (point->x * x->img->blocksize)));
}
