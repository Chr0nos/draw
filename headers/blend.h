/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:40:35 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:43:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLEND_H
# define BLEND_H
# define A(C) ((C & 0xFF000000) >> 24)
# define R(C) ((C & 0x00FF0000) >> 16)
# define G(C) ((C & 0x0000FF00) >> 8)
# define B(C) (C & 0x000000FF)

unsigned int		to_rgb(unsigned int a, unsigned int r,
				unsigned int g, unsigned int b);
unsigned int		blend_normal(unsigned int a, unsigned int b);
unsigned int		blend_overlay(unsigned int a, unsigned int b);
unsigned int		blend_lighten(unsigned int a, unsigned int b);
unsigned int		blend_darken(unsigned int a, unsigned int b);
unsigned int		blend_add(unsigned int a, unsigned int b);
unsigned int		blend_sub(unsigned int a, unsigned int b);
unsigned int		blend_multiply(unsigned int a, unsigned int b);

#endif
