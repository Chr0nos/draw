/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sethook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:58:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/19 13:15:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void	draw_sethook(t_mlx *x, int (*f)(int, void*), void *userdata)
{
	mlx_key_hook(x->winptr, f, userdata);
}

/*
** this function allow better implementations for keys hooks with mlx
** parameters:
** 2 : KEYDOWN / 3 : KEYRLZ
** -1 : useless : not used by mlx
** f : function pointer to call at each call
*/

void	draw_sethook_ng(t_mlx *x, int (*f)(), void *userdata,
		const enum e_hook hook)
{
	mlx_hook(x->winptr, hook, 1, f, userdata);
}
