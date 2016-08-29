/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_darken.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:45:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:46:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blend.h"

unsigned int		blend_darken(unsigned int a, unsigned int b)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	alpha;

	red = (R(a) < R(b) ? R(a) : R(b));
	green = (G(a) < G(b) ? G(a) : G(b));
	blue = (B(a) < B(b) ? B(a) : B(b));
	alpha = (A(a) < A(b)) ? A(a) : A(b);
	return (to_rgb(alpha, red, green, blue));
}
