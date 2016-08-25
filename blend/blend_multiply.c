/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_multiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:47:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:47:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blend.h"

unsigned int		blend_multiply(unsigned int a, unsigned int b)
{
	const unsigned int	red = (R(a) * R(b)) / 255;
	const unsigned int	green = (G(a) * G(b)) / 255;
	const unsigned int	blue = (B(a) * B(b)) / 255;
	const unsigned int	alpha = (A(a) * A(b)) / 255;

	return (to_rgb(alpha, red, green, blue));
}
