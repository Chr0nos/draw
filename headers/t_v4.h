/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_v4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 21:36:56 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/22 17:36:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_V4_H
# define T_V4_H

typedef struct		s_v4f
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_v4f;

typedef struct		s_v4d
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_v4d;

typedef struct		s_m4
{
	t_v4d			x;
	t_v4d			y;
	t_v4d			z;
	t_v4d			w;
}					t_m4;

typedef struct		s_m4f
{
	t_v4f			x;
	t_v4f			y;
	t_v4f			z;
	t_v4f			w;
}					t_m4f;

typedef struct		s_v4i
{
	int				x;
	int				y;
	int				z;
	int				w;
}					t_v4i;

typedef struct		s_v4ui
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	w;
}					t_v4ui;

#endif
