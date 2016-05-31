/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tperspective.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 21:09:02 by alhote            #+#    #+#             */
/*   Updated: 2016/05/31 11:31:35 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TPERSPECTIVE_H
# define TPERSPECTIVE_H

typedef struct	s_perspective
{
	float		fov;
	float		aspect;
	float		neardist;
	float		fardist;
	int			lefthanded:1;
}				t_perspective;
#endif
