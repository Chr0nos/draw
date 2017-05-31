/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:23:04 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/31 22:40:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H
# include "t_v3.h"
# include "t_v4.h"

/*
** r : reel
** i, j, k : imaginaires
*/

typedef struct		s_quaternion
{
	double			r;
	double			i;
	double			j;
	double			k;
}					t_quaternion;

t_quaternion		geo_quat_identity(void);
t_quaternion		geo_quat_rot(t_v3d axis, double rot);
t_quaternion		geo_quat_mult(const t_quaternion a, const t_quaternion b);
t_quaternion		geo_quat_inv(const t_quaternion q);
t_m4				geo_quat_tomatrix(const t_quaternion q);
t_m4				geo_quat_tomatrix_offset(const t_quaternion q,
		const t_v4d offset);
#endif
