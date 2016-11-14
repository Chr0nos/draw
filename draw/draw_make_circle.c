/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:16:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 20:25:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_circle	draw_make_circle(int x1, int y1, int radius)
{
	t_circle	c;

	c.center.x = x1;
	c.center.y = y1;
	c.radius = radius;
	return (c);
}
