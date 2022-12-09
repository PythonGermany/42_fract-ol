/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:46:43 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/28 19:46:43 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"

# define WIDTH 500
# define HEIGHT 500

typedef struct dta_s
{
	mlx_t *mlx;
	mlx_image_t *img;
	int (*f)(struct dta_s *);
	char **argv;
	double scale;
	double xs;
	double ys;
	int iter;
	double re;
	double im;
	double x;
	double y;
} dta_t;

//Fractals
int julia(dta_t *dta);
int mandelbrot(dta_t *dta);
int tricorn(dta_t *dta);

//Colors
int range(int out_max, int in_max, int in_curr);
uint32_t get_color(int r, int g, int b, int a);
uint32_t transform_color_range(dta_t *dta);

//Hooks
void key_hook(void *dta);
void scroll_hook(double xdelta, double ydelta, void *param);
void	mouse_hook(mouse_key_t bt, action_t ac, modifier_key_t md, void* dta);

//Main
void populate_dta(dta_t *dta);
void calculate_window(dta_t *dta);

#endif