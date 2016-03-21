/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:02:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 16:43:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void	draw_loop(t_mlx *x)
{
	mlx_loop(x->mlxptr);
}

void	draw_loop_hook(t_mlx *x, int (*display)(), void *userdata)
{
	mlx_loop_hook(x->mlxptr, display, userdata);
}
