/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_flush_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 17:18:14 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 17:27:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void	draw_flush_image(t_mlx *x, t_mlx_img *img)
{
	mlx_put_image_to_window(x->mlxptr, x->winptr, img->img, 0, 0);
}
