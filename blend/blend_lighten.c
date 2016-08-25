/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_lighten.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:45:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:45:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blend.h"

unsigned int		blend_lighten(unsigned int a, unsigned int b)
{
	const unsigned int	red = (R(a) > R(b) ? R(a) : R(b));
	const unsigned int	green = (G(a) > G(b) ? G(a) : G(b));
	const unsigned int	blue = (B(a) > B(b) ? B(a) : B(b));
	const unsigned int	alpha = (A(a) > A(b)) ? A(a) : A(b);

	return (to_rgb(alpha, red, green, blue));
}
