/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move_pxlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:32:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:18:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <string.h>

t_v2i	*draw_move_pxlist(t_v2i *tab, size_t size, int x, int y)
{
	size_t	p;

	p = 0;
	while (p < size)
	{
		tab[p].x += x;
		tab[p].y += y;
		p++;
	}
	return (tab);
}
