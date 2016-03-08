/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_topxtab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:58:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 15:06:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <string.h>
#include <math.h>

t_point		*draw_matrix_topxtab(t_point *tab, size_t size, t_matrix *t)
{
	size_t		p;
	t_vector	v;

	p = 0;
	while (p < size)
	{
		v = draw_make_vector((float)tab[p].x, (float)tab[p].y, 0.0f);
		v = draw_matrix_multiply(v, t);
		tab[p].x = (int)lroundf(v.x);
		tab[p].y = (int)lroundf(v.y);
		p++;
	}
	return (tab);
}
