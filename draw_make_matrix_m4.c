/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_m4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 01:53:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/01 21:25:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_m4	draw_make_matrix_m4_identity(void)
{
	return ((t_m4) {
		(t_v4d){1.0, 0.0, 0.0, 0.0},
		(t_v4d){0.0, 1.0, 0.0, 0.0},
		(t_v4d){0.0, 0.0, 1.0, 0.0},
		(t_v4d){0.0, 0.0, 0.0, 1.0}
	});
}

t_m4	draw_make_matrix_m4_iso(int x, int y, int w, int h)
{
	return ((t_m4) {
		(t_v4d){(double)w, 0.0, 0.0, 0.0},
		(t_v4d){0.0, (double)h, 0.0, 0.0},
		(t_v4d){0.0, 0.0, 1.0, 0.0},
		(t_v4d){(double)x, (double)y, 0.0, 0.0}
	});
}

t_m4	draw_make_matrix_m4_ortho(const t_v4d s, const t_v4d c)
{
	return ((t_m4){
		(t_v4d){s.x, 0.0, 0.0, c.x},
		(t_v4d){0.0, 0.0, s.y, c.y},
		(t_v4d){0.0, s.z, 0.0, c.z},
		(t_v4d){0.0, 0.0, 0.0, s.w}
	});
}
