/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_topxtab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:58:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 14:24:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <string.h>
#include <math.h>

t_v2i		*draw_matrix_topxtab(t_v2i *tab, size_t size, t_matrix *t)
{
	size_t		p;
	t_v3f		v;

	p = 0;
	while (p < size)
	{
		v = geo_apply((t_v3f){(float)tab[p].x, (float)tab[p].y, 0.0f}, t);
		tab[p].x = (int)lroundf(v.x);
		tab[p].y = (int)lroundf(v.y);
		p++;
	}
	return (tab);
}
