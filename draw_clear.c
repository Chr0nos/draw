/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:06:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 17:11:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void	draw_clear(t_mlx *x)
{
	mlx_clear_window(x->mlxptr, x->winptr);
	mlx_destroy_window(x->mlxptr, x->winptr);
}
