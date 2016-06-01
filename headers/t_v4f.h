/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_v4f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 21:36:56 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/01 21:13:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_V4F_H
# define T_V4F_H

typedef struct	s_v4f
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_v4f;

typedef struct	s_v4d
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_v4d;

typedef struct	s_m4
{
	t_v4f		x;
	t_v4f		y;
	t_v4f		z;
	t_v4f		w;
}				t_m4;

#endif
