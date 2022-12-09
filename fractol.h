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
	int			param[4];
}	t_dta;

//Fractals
int			julia(t_dta *dta);
int			mandelbrot(t_dta *dta);
int			tricorn(t_dta *dta);

//Colors
uint32_t	get_color(int r, int g, int b, int a);
uint32_t	tcr(int iter, int curr, int cs);
//uint32_t	interpolate(int iter, double curr, int cs);

//Hooks
void		key_hook(void *dta);
void		scroll_hook(double xdelta, double ydelta, void *param);
void		mouse_hook(mouse_key_t bt, action_t ac, \
				modifier_key_t md, void *dta);

//Main
void		populate_dta(t_dta *dta);
void		calculate_window(t_dta *dta);

#endif