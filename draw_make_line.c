/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:00:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 15:42:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

t_line	draw_make_line(int x1, int y1, int x2, int y2)
{
	t_line	line;

	line.dx = ft_abs(x2 - x1);
	line.dy = ft_abs(y2 - y1);
	line.start.x = x1;
	line.start.y = y1;
	line.end.x = x2;
	line.end.y = y2;
	return (line);
}
