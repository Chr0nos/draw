/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_putvector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:19:00 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/04 10:37:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"
#include "libft.h"

void	geo_putvector(t_v3f v, unsigned int p)
{
	ft_printf("(t_v3f){%.*f, %.*f, %.*f}",
		p, (double)v.x,
		p, (double)v.y,
		p, (double)v.z);
}

void	geo_putv4f(t_v4f v, unsigned int p)
{
	ft_printf("(t_v4f){%.*f, %.*f, %.*f, %.*f}",
		p, (double)v.x,
		p, (double)v.y,
		p, (double)v.z,
		p, (double)v.w);
}

void	geo_putv4d(t_v4d v, unsigned int p)
{
	ft_printf("(t_v4d){%.*f, %.*f, %.*f, %.*f}", p, v.x, p, v.y, p, v.z, p,
		v.w);
}

void	geo_putm4(t_m4 m, unsigned int p)
{
	ft_putstr("(t_m4){\n\t");
	geo_putv4d(m.x, p);
	ft_putstr(",\n\t");
	geo_putv4d(m.y, p);
	ft_putstr(",\n\t");
	geo_putv4d(m.z, p);
	ft_putstr(",\n\t");
	geo_putv4d(m.w, p);
	ft_putstr("\n};");
}
