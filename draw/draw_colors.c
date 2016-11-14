/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 23:34:49 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/23 16:30:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

inline static void	set_colors(t_rgb *rgb, float *vals, const int ti)
{
	const unsigned char		l = (unsigned char)(vals[0] * 255.0f);
	const unsigned char		m = (unsigned char)(vals[1] * 255.0f);
	const unsigned char		n = (unsigned char)(vals[2] * 255.0f);
	const unsigned char		v = (unsigned char)(vals[3] * 255.0f);

	if (ti == 0)
		*rgb = (t_rgb){0xff, v, n, l};
	else if (ti == 1)
		*rgb = (t_rgb){0xff, m, v, l};
	else if (ti == 2)
		*rgb = (t_rgb){0xff, l, v, n};
	else if (ti == 3)
		*rgb = (t_rgb){0xff, l, m, v};
	else if (ti == 4)
		*rgb = (t_rgb){0xff, n, l, v};
	else if (ti == 5)
		*rgb = (t_rgb){0xff, v, l, m};
}

unsigned int		draw_color_hsv(int t, float s, float v)
{
	unsigned int	color;
	int				ti;
	float			f;
	float			vals[4];

	if (t < 0)
		t *= -1;
	if (t > 360)
		t %= 360;
	ti = (t / 60) % 6;
	f = ((float)t / 60.0f) - (float)ti;
	vals[0] = v * (1.0f - s);
	vals[1] = v * (1.0f - f * v);
	vals[2] = v * (1.0f - (1.0f - f) * s);
	vals[3] = v;
	set_colors((t_rgb*)&color, vals, ti);
	return (color);
}

int					draw_color_rgb2int(t_rgb *rgb)
{
	return ((rgb->b & 0x000000ff) | ((rgb->g << 8) & 0x0000ff00) |
		((rgb->r << 16) & 0x00ff0000));
}
