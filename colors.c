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

uint32_t	tcr(int iter, int curr, int cs)
{
	int	c;

	c = range(255 * 6 + 1, iter, curr);
	if (c == 255 * 6 + 1)
		return (get_color(0, 0, 0, 255));
	c += cs;
	if (c <= 255 && !cs)
		return (get_color(c, 0, 0, c));
	if (c <= 255 && cs)
		return (get_color(255, 0, 255 - c, 255));
	if (c <= 255 * 2)
		return (get_color(255, c - 255, 0, 255));
	if (c <= 255 * 3)
		return (get_color(255 * 3 - c, 255 , 0, 255));
	if (c <= 255 * 4)
		return (get_color(0, 255, c - 255 * 3, 255));
	if (c <= 255 * 5)
		return (get_color(0, 255 * 5 - c, 255, 255));
	return (get_color(c - 255 * 5, 0, 255, 255));
}

// uint32_t	lin_inter(uint32_t c1, uint32_t c2, double f)
// {
// 	uint8_t		dr;
// 	uint8_t		dg;
// 	uint8_t		db;
// 	uint8_t		da;

// 	dr = (c2 - c1) << 24;
// 	dg = (c2 - c1) << 16;
// 	db = (c2 - c1) << 8;
// 	da = (c2 - c1) & 0xFF;
// 	return (get_color((c2 << 24) + dr * f, (c2 << 16) + dg * f,
// 		(c2 << 8) + db * f, (c2 & 0xFF) + da * f));

// }

// uint32_t interpolate(int iter, double curr, int cs)
// {
// 	return (lin_inter(tcr(iter, curr, cs),
// 		tcr(iter, curr + 1, cs), curr - (int)curr));
// }
