/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:31:38 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/30 23:52:10 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	chk_precision(char *str)
{
	int	i;
	int	precision;

	i = 0;
	precision = 0;
	if (str == NULL)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && precision)
			return (1);
		else if (str[i] == '.' && !precision)
			precision = 1;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

double	ft_precision_atoi(char *str)
{
	double	nb;
	int		i;
	double	precision;

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

void	populate_dta(t_dta *dta)
{
	dta->scale = 4;
	dta->xs = 0;
	dta->ys = 0;
	dta->iter = 50;
	dta->cs = 0;
	if (dta->argv[1][0] == 'j')
	{
		dta->re = ft_precision_atoi(dta->argv[2]);
		dta->im = ft_precision_atoi(dta->argv[3]);
		dta->f = &julia;
	}
	else if (dta->argv[1][0] == 'm')
		dta->f = &mandelbrot;
	else if (dta->argv[1][0] == 't')
		dta->f = &tricorn;
}

void	calculate_window(t_dta *dta)
{
	int	i;
	int	i2;

	i = 0;
	while (i < HEIGHT)
	{
		i2 = 0;
		while (i2 < WIDTH)
		{
			dta->x = (i2 - WIDTH / 2.0) * dta->scale / WIDTH + dta->xs;
			dta->y = (HEIGHT / 2.0 - i) * dta->scale / HEIGHT + dta->ys;
			mlx_put_pixel(dta->img, i2++, i, \
				tcr(dta->iter, (*dta->f)(dta), &dta->cs));
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dta	dta[1];

	if (argc < 2 || ft_strlen(argv[1]) != 1 || \
		(argv[1][0] != 'j' && argv[1][0] != 'm' && argv[1][0] != 't'))
		return (ft_printf("Use: %s ['m' or \"j [double] [double]\" or 't']\n", \
			argv[0]), 1);
	if (argv[1][0] == 'j' && \
		(argc != 4 || chk_precision(argv[2]) || chk_precision(argv[3])))
		return (ft_printf("Use: %s j [double] [double]\n", argv[0]), 1);
	else if (argc != 2 && (argv[1][0] == 'm' || argv[1][0] == 't'))
		return (ft_printf("Use: %s %s\n", argv[0], argv[1]), 1);
	dta->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!dta->mlx)
		return (1);
	dta->argv = argv;
	populate_dta(dta);
	dta->img = mlx_new_image(dta->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(dta->mlx, dta->img, 0, 0) == -1)
		return (1);
	mlx_scroll_hook(dta->mlx, &scroll_hook, dta);
	mlx_mouse_hook(dta->mlx, &mouse_hook, dta);
	mlx_loop_hook(dta->mlx, &key_hook, dta);
	mlx_loop(dta->mlx);
	mlx_terminate(dta->mlx);
	return (0);
}
