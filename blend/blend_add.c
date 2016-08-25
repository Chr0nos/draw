/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:46:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:46:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blend.h"

unsigned int		blend_add(unsigned int a, unsigned int b)
{
	const unsigned int	red = R(a) + R(b);
	const unsigned int	green = G(a) + G(b);
	const unsigned int	blue = B(a) + B(b);
	const unsigned int	alpha = A(a) + A(b);

	return (to_rgb(alpha, red, green, blue));
}
