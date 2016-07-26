/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pxtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:42:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:18:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <string.h>

void	draw_pxtab(t_draw *d, t_v2i *tab, size_t size,
	unsigned int color)
{
	size_t	p;

	d->color = color;
	p = 0;
	while (p < size)
	{
		draw_px(d, tab[p]);
		p++;
	}
}
