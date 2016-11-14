/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:00:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/27 01:18:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

t_line	draw_make_line(int x1, int y1, int x2, int y2)
{
	return ((t_line){(t_v2i){x1, y1}, (t_v2i){x2, y2},
		ft_abs(x2 - x1), ft_abs(y2 - y1)});
}
