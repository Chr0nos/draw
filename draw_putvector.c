/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_putvector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:19:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/02 17:28:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_putvector(t_vector v, unsigned int p)
{
	char	*s[3];

	s[0] = ft_dtoa((double)v.x, p);
	s[1] = ft_dtoa((double)v.y, p);
	s[2] = ft_dtoa((double)v.z, p);
	ft_printf("(t_v3f){%s, %s, %s}", s[0], s[1], s[2]);
	ft_free_tab(s, 3);
}

void	draw_putv4f(t_v4f v, unsigned int p)
{
	char	*s[4];

	s[0] = ft_dtoa((double)v.x, p);
	s[1] = ft_dtoa((double)v.y, p);
	s[2] = ft_dtoa((double)v.z, p);
	s[3] = ft_dtoa((double)v.w, p);
	ft_printf("(t_v4f){%s, %s, %s, %s}", s[0], s[1], s[2], s[3]);
	ft_free_tab(s, 4);
}

void	draw_putv4d(t_v4d v, unsigned int p)
{
	char	*s[4];

	s[0] = ft_dtoa(v.x, p);
	s[1] = ft_dtoa(v.y, p);
	s[2] = ft_dtoa(v.z, p);
	s[3] = ft_dtoa(v.w, p);
	ft_printf("(t_v4d){%s, %s, %s, %s}", s[0], s[1], s[2], s[3]);
	ft_free_tab(s, 4);
}

void	draw_putm4(t_m4 m, unsigned int p)
{
	ft_putstr("(t_m4){\n\t");
	draw_putv4d(m.x, p);
	ft_putstr(",\n\t");
	draw_putv4d(m.y, p);
	ft_putstr(",\n\t");
	draw_putv4d(m.z, p);
	ft_putstr(",\n\t");
	draw_putv4d(m.w, p);
	ft_putstr("\n};");
}
