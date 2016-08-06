/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_smoothstep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:27:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/06 17:29:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

t_v2f		geo_smoothstep(t_v2f a, t_v2f b, t_v2f x)
{
	const t_v2f t = {
		geo_clamp((x.x - a.x) / (b.x - a.x), 0.0f, 1.0f),
		geo_clamp((x.y - a.y) / (b.x - a.y), 0.0f, 1.0f),
	};

	return ((t_v2f){t.x * t.x * (3.0f - 2.0f * t.x),
		t.y * t.y * (3.0f - 2.0f * t.y)});
}
