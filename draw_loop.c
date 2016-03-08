/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:02:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/12 14:03:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void	draw_loop(t_mlx *x)
{
	mlx_loop(x->mlxptr);
}

void	draw_loop_hook(t_mlx *x, int (*display)(void *user), void *userdata)
{
	mlx_loop_hook(x->mlxptr, display, userdata);
}
