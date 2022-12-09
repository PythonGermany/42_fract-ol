#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	dta->scale = 2.5;
	dta->xs = -0.7;
	dta->ys = 0;
	dta->iter = 350;
	dta->cs = 25;
	dta->cs_active = 0;
	if (dta->argv[2][0] == 'j')
	{
		dta->re = ft_precision_atoi(dta->argv[3]);
		dta->im = ft_precision_atoi(dta->argv[4]);
		dta->f = &julia;
	}
	else if (dta->argv[2][0] == 'm')
		dta->f = &mandelbrot;
	else if (dta->argv[2][0] == 't')
		dta->f = &tricorn;
}

void	calculate_window(t_dta *dta)
{
	FILE *file;
	int size;
	int	i;
	int	i2;
	int c;

	file = fopen("test.ppm", "wb");
	size = ft_atoi(dta->argv[1]);
	fprintf(file, "P6\n%d\n%d\n255\n", size, size);
	i = 0;
	while (i < size)
	{
		i2 = 0;
		while (i2 < size)
		{
			dta->x = (i2 - size / 2.0) * dta->scale / size + dta->xs;
			dta->y = (size / 2.0 - i) * dta->scale / size + dta->ys;
			c = tcr(dta->iter, (*dta->f)(dta), &dta->cs);
			fwrite((unsigned char *)(&c) + 3, 1, 1, file);
			fwrite((unsigned char *)(&c) + 2, 1, 1, file);
			fwrite((unsigned char *)(&c) + 1, 1, 1, file);
			i2++;
		}
		if (i % 100 == 0)
			printf("Line: %i\n",i );
		i++;
	}
	fclose(file);
}

int	main(int argc, char **argv)
{
	t_dta	dta[1];

	if (argc < 2)
		return (1);
	/*if (argc < 3 || strlen(argv[2]) != 1 || \
		(argv[2][0] != 'j' && argv[2][0] != 'm' && argv[2][0] != 't'))
		return (printf("Use: %s ['m' or \"j [double] [double]\" or 't']\n", \
			argv[0]), 1);
	if (argv[2][0] == 'j' && \
		(argc != 5 || chk_precision(argv[3]) || chk_precision(argv[4])))
		return (printf("Use: %s j [double] [double]\n", argv[0]), 1);
	else if (argc != 3 && (argv[2][0] == 'm' || argv[2][0] == 't'))
		return (printf("Use: %s %s\n", argv[0], argv[2]), 1);*/
	dta->argv = argv;
	populate_dta(dta);
	calculate_window(dta);
	return (0);
}
