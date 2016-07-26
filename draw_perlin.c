/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perlin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:08:36 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 00:26:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void				perlin_init(unsigned char *map, int p, float **g2)
{
	const float		unit = 1.0f / sqrtf(2.0f);

	while (p--)
		map[p] = (unsigned char)(rand() & 0xff);
	g2[0] = (float[2]){unit, unit};
	g2[1] = (float[2]){-unit, unit};
	g2[2] = (float[2]){unit, -unit};
	g2[3] = (float[2]){-unit, -unit};
	g2[4] = (float[2]){1.0, 0.0};
	g2[5] = (float[2]){-1.0, 1.0};
	g2[6] = (float[2]){1.0, 1.0};
	g2[7] = (float[2]){0.0, 1.0};
	g2[8] = (float[2]){0.0, -1.0};
}

static unsigned int		perlin_v(const unsigned char *perm, const t_v2i px)
{
	return ((unsigned int)(perm[px.x + perm[px.y] % 8] |
		(perm[px.x + 1 + perm[px.y] % 8] << 8) |
		(perm[px.x + perm[px.y + 1] % 8]) << 16 |
		(perm[px.x + 1 + perm[px.y + 1] % 8]) << 24));
}

static unsigned int		perlin_ponderate(const t_v2i tmp, const float *g2)
{
	return ((unsigned int)(g2[0] * tmp.x + g2[1] * tmp.y));
}

static double			perlin_liss(t_v2i px, t_v2f geo, const t_v4ui *ponder)
{
	t_v2i		tmp;
	t_v2f		c;
	float		li[2];

	tmp = (t_v2i){(int)(geo.x - (float)px.x), (int)(geo.y - (float)px.y)};
	c = (t_v2f){3 * tmp.x * tmp.x - 2 * tmp.x * tmp.x * tmp.x,
				3 * tmp.y * tmp.y - 2 * tmp.y * tmp.y * tmp.y};
	li[0] = ponder->x + c.x * (ponder->y - ponder->x);
	li[1] = ponder->z + c.x * (ponder->z - ponder->w);
	return ((double)(li[0] + c.y * (li[1] - li[0])));
}
#include <stdio.h>
double					draw_perlin_noise(t_v2f geo, float res)
{
	float			g2[8][2];
	unsigned char	perm[256];
	t_v2i			px;
	t_v4ui			ponder;
	unsigned int	v;

	perlin_init(perm, 256, (float**)(unsigned long)g2);
	geo = (t_v2f){geo.x * res, geo.y * res};
	px = (t_v2i){(int)geo.x, (int)geo.y};
	v = perlin_v(perm, px);
	ponder.x = perlin_ponderate(
		(t_v2i){(int)(geo.x - (float)px.x), (int)(geo.y - (float)px.y)},
		(const float *)g2[v & 0xff]);
	ponder.y = perlin_ponderate(
		(t_v2i){(int)(geo.x - (float)(px.x + 1)), (int)(geo.y - (float)px.y)},
		(const float *)g2[(v & 0xff00) >> 8]);
	ponder.z = perlin_ponderate(
		(t_v2i){(int)(geo.x - (float)px.x), (int)(geo.y - (float)(px.y + 1))},
		(const float *)g2[(v & 0xff0000) >> 16]);
	ponder.w = perlin_ponderate(
		(t_v2i){(int)(geo.x - (float)(px.x + 1)),
			(int)(geo.y - (float)(px.y + 1))},
		(const float *)g2[(v & 0xff000000) >> 24]);
	printf("ponders: %u %u %u %u\n", ponder.x, ponder.y, ponder.z, ponder.w);
	return (perlin_liss(px, geo, &ponder));
}
