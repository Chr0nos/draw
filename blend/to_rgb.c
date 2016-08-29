/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:39:54 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:50:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blend.h"

unsigned int		to_rgb(unsigned int a, unsigned int r,
				unsigned int g, unsigned int b)
{
	return ((((a > 0xff) ? 0xff : a) << 24) |
		(((r > 0xff) ? 0xff : r) << 16) |
		(((g > 0xff) ? 0xff : g) << 8) |
		((b > 0xff) ? 0xff : b));
}
