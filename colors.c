/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:51:39 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/28 19:51:39 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	range(int out_max, int in_max, int in_curr)
{
	return ((double)in_curr / in_max * out_max);
}

uint32_t	get_color(int r, int g, int b, int a)
{
	return ((r <<= 24) + (g <<= 16) + (b <<= 8) + (a & 0xFF));
}

uint32_t	transform_color_range(t_dta *dta)
{
	int	c;

	c = range(255 * 4, dta->iter, (*dta->f)(dta)) - dta->cs;
	if (c <= 255)
		return (get_color(c, 0, 0, c));
	if (c <= 255 * 2)
		return (get_color(0, 255 - c, 0, 255));
	if (c <= 255 * 3)
		return (get_color(0, 0, 255 - c, 255));
	if (c <= 255 * 4)
		return (get_color(255 - c, 255 - c, 255 - c, 255));
	return (get_color(0, 0, 0, 255));
}
