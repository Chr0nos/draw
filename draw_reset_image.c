/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 19:53:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/12 12:59:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_reset_image(t_mlx *x, int color)
{
	const size_t	block = (size_t)x->img->bpp / 8;
	const size_t	size = (size_t)x->width * (size_t)x->height * block;
	char			*img;
	size_t			p;

	img = x->img->data;
	p = 0;
	while (p < size)
	{
		ft_memcpy(img + p, &color, block);
		p += block;
	}
}
