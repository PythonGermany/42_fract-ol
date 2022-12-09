/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:31:38 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/27 22:40:00 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "MLX42.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#define WIDTH 500
#define HEIGHT 500

typedef struct dta_s
{
	mlx_t *mlx;
	mlx_image_t	*img;
	char **argv;
	double scale;
	double x_shift;
	double y_shift;
	int iter;
	double re;
	double im;
	double x;
	double y;
}	dta_t;

int mandelbrot(dta_t *dta)
{
	int n;
	double x_re;
	double y_im;
	double x_buf;

	n = 0;
	x_re = 0;
	y_im = 0;
	while (x_re*x_re + y_im*y_im <= 4 && n < dta->iter)
	{
		x_buf = x_re*x_re - y_im*y_im + dta->re;
		y_im = 2*x_re*y_im + dta->im;
		x_re = x_buf;
        n++;
	}
	return (n);
}

int tricorn(dta_t *dta)
{
	int n;
	double x_re;
	double y_im;
	double x_buf;

	n = 0;
	x_re = 0;
	y_im = 0;
	while (x_re*x_re + y_im*y_im <= 4 && n < dta->iter)
	{
		x_buf = x_re*x_re - y_im*y_im + dta->re;
		y_im = -2*x_re*y_im + dta->im;
		x_re = x_buf;
        n++;
	}
	return (n);
}

int julia(dta_t *dta)
{
	int n;
	double x_buf;

	n = 0;
	while (dta->x*dta->x + dta->y*dta->y <= 4 && n < dta->iter)
	{
		x_buf = dta->x*dta->x - dta->y*dta->y + dta->re;
		dta->y = 2*dta->x*dta->y + dta->im;
		dta->x = x_buf;
        n++;
	}
	return (n);
}

int range(int out_max, int in_max, int in_curr)
{
	return ((float)in_curr / in_max * out_max);
}

uint32_t get_color(int r, int g, int b, int a)
{
	return ((r <<= 24) + (g <<= 16) + (b <<= 8) + (a & 0xFF));
}

uint32_t transform_color_range(dta_t *dta)
{
	int c;
	int ret;
	
	if (dta->argv[1][0] == 'j')
		ret = julia(dta);
	else if (dta->argv[1][0] == 'm')
		ret = mandelbrot(dta);
	else
		ret = tricorn(dta);
	// if (ret >= dta->iter)
	// 	return (0xFF);
	c = range(255, dta->iter / 4, ret / 4);
	//return (get_color(255 - c, 255, 255 - c , 255));
	return (get_color(255 - c, 255 - c, 255 - c , 255));
}

void	calculate_window(dta_t *dta)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (i < HEIGHT)
	{
		i2 = 0;
		while (i2 < WIDTH)
		{
			if (dta->argv[1][0] == 'j')
			{
				dta->x = ((i2 - WIDTH / 2.0) * dta->scale) / WIDTH + dta->x_shift;
				dta->y = -((i - HEIGHT / 2.0) * dta->scale) / HEIGHT + dta->y_shift;
			}
			else
			{
				dta->re = ((i2 - WIDTH / 2.0) * dta->scale) / WIDTH + dta->x_shift;
       			dta->im = -((i - HEIGHT / 2.0) * dta->scale) / HEIGHT + dta->y_shift;
			}
			mlx_put_pixel(dta->img, i2, i, transform_color_range(dta));
			i2++;
		}
		i++;
	}
}

double	ft_precision_atoi(char *str)
{
	double	nb;
	int i;
	double precision;

	nb = ft_atoi(str);
	precision = 0.1;
	i = 0;
	if (str[i] == '-')
		precision *= -1;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i])
		{
			nb += precision * (str[i++] - '0');
			precision /= 10;
		}
	}
	return (nb);
}

void populate_dta(dta_t *dta)
{
	dta->scale = 4;
	dta->x_shift = 0;
	dta->y_shift = 0;
	dta->iter = 40;
	if (dta->argv[1][0] == 'j')
	{
		dta->re = ft_precision_atoi(dta->argv[2]); // -0.835
		dta->im = ft_precision_atoi(dta->argv[3]); // -0.2321
	}
}

void	hook(void *dta)
{
	dta_t	*temp;

	temp = (dta_t *)dta;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(temp->mlx);
	if (mlx_is_key_down(temp->mlx, MLX_KEY_1))
		temp->iter -= 1;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_2))
		temp->iter += 1;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_3))
		temp->scale *= 1.05;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_4))
	{
		temp->scale /= 1.05;
		printf("Zoom: %lf\n", temp->scale);
	}
	if (mlx_is_key_down(temp->mlx, MLX_KEY_UP))
		temp->y_shift += 0.01 * temp->scale;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_DOWN))
		temp->y_shift -= 0.01 * temp->scale;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_LEFT))
		temp->x_shift -= 0.01 * temp->scale;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_RIGHT))
		temp->x_shift += 0.01 * temp->scale;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_5))
		temp->re -= 0.01;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_6))
		temp->re += 0.01;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_7))
		temp->im -= 0.01;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_8))
		temp->im += 0.01;
	if (mlx_is_key_down(temp->mlx, MLX_KEY_R))
		populate_dta(temp);
	calculate_window(temp);
}

// mlx_mousefunc mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void* dta)
// {
// 	ft_printf("Mouse: %i\n", button);
// }

int	main(int argc, char **argv)
{
	dta_t dta[1];

	if (argc < 2)
		return (1);
	if (ft_strlen(argv[1]) != 1 || (argv[1][0] != 'j' && argv[1][0] != 'm' && argv[1][0] != 't'))
		return (ft_printf("Use: %s ['m' or 'j' or 't']\n", argv[0]), 1);
	if (argv[1][0] == 'j' && argc != 4)
		return (ft_printf("Use: %s j [double] [double]\n", argv[0]), 1);
	dta->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	dta->argv = argv;
	if (!dta->mlx)
		exit(EXIT_FAILURE);
	populate_dta(dta);
	dta->img = mlx_new_image(dta->mlx, WIDTH, HEIGHT);
	calculate_window(dta);
	mlx_image_to_window(dta->mlx, dta->img, 0, 0);
	mlx_loop_hook(dta->mlx, &hook, dta);
	//mlx_mouse_hook(dta->mlx, &mouse_hook, dta);
	mlx_loop(dta->mlx);
	mlx_terminate(dta->mlx);
	return (EXIT_SUCCESS);
}