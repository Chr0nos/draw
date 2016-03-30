/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 19:53:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 15:20:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_reset_image(t_mlx *x, unsigned int color)
{
	size_t			p;
	const size_t	size = (size_t)(x->img->width * x->height);
	unsigned long	blk;

	blk = (unsigned long)color | (unsigned long)color << 32;
	p = 0;
	while (p < size)
	{
		*(unsigned long *)((unsigned long)x->img->data + p) = blk;
		p += 8;
	}
}
