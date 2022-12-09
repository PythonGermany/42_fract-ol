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

int range(int out_max, int in_max, int in_curr)
{
	return ((double)in_curr / in_max * out_max);
}

uint32_t get_color(int r, int g, int b, int a)
{
	return ((r <<= 24) + (g <<= 16) + (b <<= 8) + (a & 0xFF));
}

uint32_t transform_color_range(dta_t *dta)
{
	int c;

	c = 255 - range(255, dta->iter, (*dta->f)(dta));
	return (get_color(c, c, c, 255));
}
