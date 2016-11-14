/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:19:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		draw_rect(t_draw *d, t_rect rect, unsigned int color)
{
	t_v2i		pts[5];

	pts[0] = (t_v2i){rect.start.x, rect.start.y};
	pts[1] = (t_v2i){rect.end.x, rect.start.y};
	pts[2] = (t_v2i){rect.end.x, rect.end.y};
	pts[3] = (t_v2i){rect.start.x, rect.end.y};
	pts[4] = (t_v2i){rect.start.x, rect.start.y};
	draw_perimeter(d, pts, 5, color);
}
