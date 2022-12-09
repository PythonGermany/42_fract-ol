/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:12:29 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/28 20:12:29 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>

int i = 0;
int ms_g = 0;

void	key_act_d(mlx_t *mlx, keys_t key, double *n, double op)
{
	if (mlx_is_key_down(mlx, key))
		*n += op;
}

void	key_act_i(mlx_t *mlx, keys_t key, int *n, int op)
{
	if (mlx_is_key_down(mlx, key))
		*n = op;
}

void	key_hook(void *dta)
{
	t_dta	*tmp;
	int32_t x;
	int32_t y;

	tmp = (t_dta *)dta;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(tmp->mlx);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_R))
		populate_dta(tmp);
	key_act_i(tmp->mlx, MLX_KEY_MINUS, &tmp->iter, tmp->iter / 1.1 + 1);
	key_act_i(tmp->mlx, MLX_KEY_EQUAL, &tmp->iter, tmp->iter * 1.1);
	key_act_i(tmp->mlx, MLX_KEY_C, &tmp->cs, tmp->cs + 8);
	key_act_d(tmp->mlx, MLX_KEY_UP, &tmp->ys, 0.02 * tmp->scale);
	key_act_d(tmp->mlx, MLX_KEY_DOWN, &tmp->ys, -0.02 * tmp->scale);
	key_act_d(tmp->mlx, MLX_KEY_LEFT, &tmp->xs, -0.02 * tmp->scale);
	key_act_d(tmp->mlx, MLX_KEY_RIGHT, &tmp->xs, 0.02 * tmp->scale);
	if (mlx_is_mouse_down(tmp->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		mlx_get_mouse_pos(tmp->mlx, &x, &y);
		tmp->re = (x - WIDTH / 2) * tmp->scale / WIDTH;
		tmp->im = (HEIGHT / 2 - y) * tmp->scale / HEIGHT;
	}
	clock_t diff;
	clock_t start = clock();
	calculate_window(tmp);
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	ms_g += msec%1000;
	i++;
	printf("%d milliseconds, av: %d\nScale: %.20f, %d iter\nXparam %f, Yparam %f\nCshift: %d\n\n", msec%1000, ms_g / i, tmp->scale, tmp->iter, tmp->re, tmp->im, tmp->cs);

}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_dta	*tmp;
	int		x;
	int		y;

	(void)xdelta;
	tmp = (t_dta *)param;
	mlx_get_mouse_pos(tmp->mlx, &x, &y);
	if (ydelta > 0)
	{
		tmp->scale /= 1.2;
		tmp->xs += (x - WIDTH / 2) * tmp->scale / WIDTH * 0.2;
		tmp->ys += (HEIGHT / 2 - y) * tmp->scale / HEIGHT * 0.2;
	}
	if (ydelta < 0)
	{
		tmp->scale *= 1.2;
		tmp->xs += (x - WIDTH / 2) * tmp->scale / WIDTH * -(1 - 1 / 1.2);
		tmp->ys += (HEIGHT / 2 - y) * tmp->scale / HEIGHT * -(1 - 1 / 1.2);
	}
}

void	mouse_hook(mouse_key_t bt, action_t ac, modifier_key_t md, void *dta)
{
	static int	x_start;
	static int	y_start;
	static int	x_stop;
	static int	y_stop;
	t_dta		*tmp;

	(void)md;
	tmp = (t_dta *)dta;
	if (bt == MLX_MOUSE_BUTTON_LEFT && ac == MLX_PRESS)
		mlx_get_mouse_pos(tmp->mlx, &x_start, &y_start);
	else if (bt == MLX_MOUSE_BUTTON_LEFT && ac == MLX_RELEASE)
	{
		mlx_get_mouse_pos(tmp->mlx, &x_stop, &y_stop);
		x_stop -= x_start;
		y_stop -= y_start;
		if (x_stop < 1 || y_stop < 1)
			return ;
		tmp->xs += (x_start + (x_stop - WIDTH) / 2) * tmp->scale / WIDTH;
		tmp->ys -= (y_start + (y_stop - HEIGHT) / 2) * tmp->scale / HEIGHT;
		if (y_stop < x_stop)
			tmp->scale *= ((double)x_stop / WIDTH);
		else
			tmp->scale *= ((double)y_stop / HEIGHT);
	}
}
