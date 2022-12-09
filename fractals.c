/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:45:36 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/28 19:45:36 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(dta_t *dta)
{
	int		n;
	double	x_buf;

	n = 0;
	while (dta->x * dta->x + dta->y * dta->y <= 4 && n < dta->iter)
	{
		x_buf = dta->x * dta->x - dta->y * dta->y + dta->re;
		dta->y = 2 * dta->x * dta->y + dta->im;
		dta->x = x_buf;
		n++;
	}
	return (n);
}

int mandelbrot(dta_t *dta)
{
	int		n;
	double	x_re;
	double	y_im;
	double	x_buf;

	n = 0;
	x_re = 0;
	y_im = 0;
	while (x_re * x_re + y_im * y_im <= 4 && n < dta->iter)
	{
		x_buf = x_re * x_re - y_im * y_im + dta->re;
		y_im = 2 * x_re * y_im + dta->im;
		x_re = x_buf;
		n++;
	}
	return (n);
}

int tricorn(dta_t *dta)
{
	int		n;
	double	x_re;
	double	y_im;
	double	x_buf;

	n = 0;
	x_re = 0;
	y_im = 0;
	while (x_re * x_re + y_im * y_im <= 4 && n < dta->iter)
	{
		x_buf = x_re * x_re - y_im * y_im + dta->re;
		y_im = -2 * x_re * y_im + dta->im;
		x_re = x_buf;
		n++;
	}
	return (n);
}