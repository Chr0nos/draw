/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 21:50:34 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 21:54:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_rect	draw_make_rect(int x1, int y1, int x2, int y2)
{
	t_rect	r;

	r.start.x = x1;
	r.start.y = y1;
	r.end.x = x2;
	r.end.y = y2;
	return (r);
}
