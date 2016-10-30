/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_proj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:06:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/30 14:36:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PROJ_H
# define T_PROJ_H

typedef struct	s_proj
{
	double		left;
	double		right;
	double		bottom;
	double		top;
	double		near;
	double		far;
}				t_proj;

#endif
