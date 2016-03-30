/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pxtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:42:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 15:21:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <string.h>

void	draw_pxtab(t_mlx *x, t_point *tab, size_t size, unsigned int color)
{
	size_t	p;

	p = 0;
	while (p < size)
	{
		draw_px(x, &tab[p], color);
		p++;
	}
}
