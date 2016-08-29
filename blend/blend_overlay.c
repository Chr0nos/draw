/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_overlay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:44:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:45:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blend.h"

unsigned int		blend_overlay(unsigned int a, unsigned int b)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = ((R(b) < 128) ? (2 * R(a) * R(b) / 255) : (255 - 2 * (255 - R(a))
	* (255 - R(b)) / 255));
	green = ((G(b) < 128) ? (2 * G(a) * G(b) / 255) : (255 - 2 * (255 - G(a))
	* (255 - G(b)) / 255));
	blue = ((B(b) < 128) ? (2 * B(a) * B(b) / 255) : (255 - 2 * (255 - B(a))
	* (255 - B(b)) / 255));
	return (to_rgb(0, red, green, blue));
}
