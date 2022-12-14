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

# define WIDTH 400
# define HEIGHT 400

typedef struct s_dta
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			(*f)(struct s_dta *);
	char		**argv;
	double		scale;
	double		xs;
	double		ys;
	int			iter;
	double		re;
	double		im;
	double		x;
	double		y;
	int			cs;
	int			cs_active;
	int			param[4];
}	t_dta;

typedef struct s_coord
{
	int	x_start;
	int	y_start;
	int	x_stop;
	int	y_stop;
}	t_coord;

//Fractals
int		julia(t_dta *dta);
int		mandelbrot(t_dta *dta);
int		tricorn(t_dta *dta);

//Colors
int		get_color(int r, int g, int b, int a);
int		tcr(int iter, int curr, int *cs);

//Hooks
void	key_hook(void *dta);
void	scroll_hook(double xdelta, double ydelta, void *param);
void	mouse_hook(mouse_key_t bt, action_t ac, \
				modifier_key_t md, void *dta);

//Main
void	populate_dta(t_dta *dta);
void	calculate_window(t_dta *dta);

#endif