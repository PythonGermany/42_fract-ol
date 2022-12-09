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

//Test info variables
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
	t_dta	*t;
	int32_t x;
	int32_t y;

	t = (t_dta *)dta;
	if (mlx_is_key_down(t->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(t->mlx);
	if (mlx_is_key_down(t->mlx, MLX_KEY_R))
		populate_dta(t);
	key_act_i(t->mlx, MLX_KEY_MINUS, &t->iter, t->iter / 1.1 + 1);
	key_act_i(t->mlx, MLX_KEY_EQUAL, &t->iter, t->iter * 1.1);
	key_act_d(t->mlx, MLX_KEY_UP, &t->ys, 0.02 * t->scale);
	key_act_d(t->mlx, MLX_KEY_DOWN, &t->ys, -0.02 * t->scale);
	key_act_d(t->mlx, MLX_KEY_LEFT, &t->xs, -0.02 * t->scale);
	key_act_d(t->mlx, MLX_KEY_RIGHT, &t->xs, 0.02 * t->scale);
	if (t->cs_active)
		t->cs += 8;
	if (mlx_is_mouse_down(t->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		mlx_get_mouse_pos(t->mlx, &x, &y);
		t->re = (x - WIDTH / 2) * t->scale / WIDTH;
		t->im = (HEIGHT / 2 - y) * t->scale / HEIGHT;
	}

	//Test info
	clock_t diff;
	clock_t start = clock();
	calculate_window(t);
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	ms_g += msec%1000;
	i++;
	printf("%d milliseconds, %d average\n\
		Scale: %.20f, %d iter\n\
		Size of set (current window view = %fmm): %fkm\n\
		Xparam %f, Yparam %f\n\
		Cshift: %d\n\n", \
		msec%1000, ms_g / i, t->scale, t->iter, (float)WIDTH / 100, \
		4 / t->scale / 1000000 * (WIDTH / 100), t->re, t->im, t->cs);

}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_dta	*t;
	int		x;
	int		y;

	(void)xdelta;
	t = (t_dta *)param;
	mlx_get_mouse_pos(t->mlx, &x, &y);
	if (ydelta > 0)
	{
		t->scale /= 1.2;
		t->xs += (x - WIDTH / 2) * t->scale / WIDTH * 0.2;
		t->ys += (HEIGHT / 2 - y) * t->scale / HEIGHT * 0.2;
	}
	if (ydelta < 0)
	{
		t->scale *= 1.2;
		t->xs += (x - WIDTH / 2) * t->scale / WIDTH * -(1 - 1 / 1.2);
		t->ys += (HEIGHT / 2 - y) * t->scale / HEIGHT * -(1 - 1 / 1.2);
	}
}

void	mouse_hook(mouse_key_t bt, action_t ac, modifier_key_t md, void *dta)
{
	static t_coord	c[1];
	t_dta			*t;

	(void)md;
	t = (t_dta *)dta;
	if (bt == MLX_MOUSE_BUTTON_LEFT && ac == MLX_PRESS)
		mlx_get_mouse_pos(t->mlx, &c->x_start, &c->y_start);
	else if (bt == MLX_MOUSE_BUTTON_LEFT && ac == MLX_RELEASE)
	{
		mlx_get_mouse_pos(t->mlx, &c->x_stop, &c->y_stop);
		c->x_stop -= c->x_start;
		c->y_stop -= c->y_start;
		if (c->x_stop < 1 || c->y_stop < 1)
			return ;
		t->xs += (c->x_start + (c->x_stop - WIDTH) / 2) * t->scale / WIDTH;
		t->ys -= (c->y_start + (c->y_stop - HEIGHT) / 2) * t->scale / HEIGHT;
		if (c->y_stop < c->x_stop)
			t->scale *= ((double)c->x_stop / WIDTH);
		else
			t->scale *= ((double)c->y_stop / HEIGHT);
	}
	if (bt == MLX_MOUSE_BUTTON_MIDDLE && ac == MLX_PRESS)
	{
		t->cs_active = !t->cs_active;
		while (!mlx_is_mouse_down(t->mlx, MLX_MOUSE_BUTTON_MIDDLE));
	}
}
