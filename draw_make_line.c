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
	return ((t_line){(t_point){x1, y1}, (t_point){x2, y2},
		ft_abs(x2 - x1), ft_abs(y2 - y1)});
}
