/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 23:34:49 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 15:41:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

inline static void	set_rgb_vals(t_rgb *rgb, unsigned char r, unsigned char g,
		unsigned  char b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

inline static void	set_colors(t_rgb *rgb, float *vals, const int ti)
{
	const unsigned char		l = (unsigned char)(vals[0] * 255.0f);
	const unsigned char		m = (unsigned char)(vals[1] * 255.0f);
	const unsigned char		n = (unsigned char)(vals[2] * 255.0f);
	const unsigned char		v = (unsigned char)(vals[3] * 255.0f);

	if (ti == 0)
		set_rgb_vals(rgb, v, n, l);
	else if (ti == 1)
		set_rgb_vals(rgb, m, v, l);
	else if (ti == 2)
		set_rgb_vals(rgb, l, v, n);
	else if (ti == 3)
		set_rgb_vals(rgb, l, m, v);
	else if (ti == 4)
		set_rgb_vals(rgb, n, l, v);
	else if (ti == 5)
		set_rgb_vals(rgb, v, l, m);
}

static void			set_rgb(t_rgb *rgb, int t, float s, float v)
{
	int		ti;
	float	f;
	float	vals[4];

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
	set_colors(rgb, vals, ti);
}

t_rgb				draw_color_hsv(int t, float s, float v)
{
	t_rgb	rgb;

	set_rgb(&rgb, t, s, v);
	return (rgb);
}

int					draw_color_rgb2int(t_rgb *rgb)
{
	return ((rgb->b & 0x000000ff) | ((rgb->g << 8) & 0x0000ff00) |
		((rgb->r << 16) & 0x00ff0000));
}
