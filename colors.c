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

#define COLOR_MAX 256 * 6

int	range(int out_max, int in_max, int in_curr)
{
	return ((double)in_curr / in_max * out_max);
}

uint32_t	get_color(int r, int g, int b, int a)
{
	return ((r <<= 24) + (g <<= 16) + (b <<= 8) + (a & 0xFF));
}

uint32_t	tcr(int iter, int curr, int *cs)
{
	int	c;
	int fa;

	fa = 0;
	c = range(COLOR_MAX, iter, curr);
	if (c == COLOR_MAX)
		return (get_color(0, 0, 0, 255));
	if (*cs >= COLOR_MAX)
		*cs = 0;
	c += *cs;
	if (c >= COLOR_MAX)
		c -= COLOR_MAX;
	if (*cs < 256 && curr < iter / 2 && c < 256 * ++fa)
		return (get_color(c, 0, 0, c));
	if ((*cs >= 256 || curr >= iter / 2) && c < 256 * ++fa)
		return (get_color(255, 0, 255 - c, 255));
	if (c < 256 * ++fa)
		return (get_color(255, c - 256, 0, 255));
	if (c < 256 * ++fa)
		return (get_color(256 * fa - c - 1, 255 , 0, 255));
	if (c < 256 * ++fa)
		return (get_color(0, 255, c - 256 * (fa - 1), 255));
	if (c < 256 * ++fa)
		return (get_color(0, 256 * fa - c - 1, 255, 255));
	return (get_color(c - 256 * (fa - 1), 0, 255, 255));
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
