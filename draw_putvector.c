/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_putvector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:19:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/31 18:22:25 by snicolet         ###   ########.fr       */
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
