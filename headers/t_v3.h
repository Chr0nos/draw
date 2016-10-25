/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_v3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 16:31:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/25 14:23:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_V3_H
# define T_V3_H

typedef struct		s_v3d
{
	double			x;
	double			y;
	double			z;
}					t_v3d;

typedef struct		s_v3f
{
	float			x;
	float			y;
	float			z;
}					t_v3f;

typedef struct		s_v3ui
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
}					t_v3ui;

typedef struct		s_v3i
{
	int				x;
	int				y;
	int				z;
}					t_v3i;

#endif
