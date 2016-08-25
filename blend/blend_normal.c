/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:44:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 08:44:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blend.h"

unsigned int		blend_normal(unsigned int a, unsigned int b)
{
	if (!A(a))
		return (a);
	else
		return (blend_add(
			blend_multiply(to_rgb(A(a), A(a), A(a), A(a)), b), a));
}
