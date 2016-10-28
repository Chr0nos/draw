/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_proj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:06:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/28 22:08:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PROJ_H
# define T_PROJ_H

typedef struct	s_proj
{
	double		left;
	double		right;
	double		top;
	double		bottom;
	double		far;
	double		near;
}				t_proj;

#endif
