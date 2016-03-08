/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:10:35 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 18:32:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include <string.h>
#include <stdlib.h>

t_mlx	*draw_init(char *name, int width, int height)
{
	t_mlx	*x;

	if (!(x = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	x->mlxptr = mlx_init();
	if (!x->mlxptr)
	{
		free(x);
		return (NULL);
	}
	if (!(x->winptr = mlx_new_window(x->mlxptr, width, height, name)))
	{
		free(x);
		return (NULL);
	}
	x->height = height;
	x->width = width;
	draw_new_image(x);
	return (x);
}
