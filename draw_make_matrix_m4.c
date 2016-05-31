/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_m4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 01:53:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/31 06:09:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_m4	draw_make_matrix_m4_identity(void)
{
	return ((t_m4){
		(t_v4f){1.0, 0.0, 0.0, 0.0},
		(t_v4f){0.0, 1.0, 0.0, 0.0},
		(t_v4f){0.0, 0.0, 1.0, 0.0},
		(t_v4f){0.0, 0.0, 0.0, 1.0},
		(t_v4f){0.0, 0.0, 0.0, 0.0}
	});
}

t_m4	draw_make_matrix_m4_iso(int x, int y, int w, int h)
{
	return ((t_m4) {
		(t_v4f){(float)w, 0.0, 0.0, 0.0},
		(t_v4f){0.0, (float)h, 0.0, 0.0},
		(t_v4f){0.0, 0.0, 1.0, 0.0},
		(t_v4f){0.0, 0.0, 0.0, 1.0},
		(t_v4f){(float)x, (float)y, 0.0, 0.0}
	});
}

t_m4	draw_make_matrix_m4_ortho(const t_v4f s, const t_v4f c)
{
	return ((t_m4){
		(t_v4f){s.x, 0.0, 0.0, 0.0},
		(t_v4f){0.0, 0.0, s.y, 0.0},
		(t_v4f){0.0, s.z, 0.0, 0.0},
		(t_v4f){0.0, 0.0, 0.0, 0.0},
		(t_v4f){c.x, c.y, c.z, c.w}
	});
}
