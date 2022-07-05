/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:09:34 by abouchfa          #+#    #+#             */
/*   Updated: 2022/07/05 05:28:06 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(int it, t_data *data)
{
	uint8_t	rgb[3];
	double	div;

	div = (double)it / (double)data->stb_lim;
	rgb[0] = 9 * (1 - div) * pow(div, 3) * 255;
	rgb[1] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
	rgb[2] = 9 * pow((1 - div), 3) * div * 255;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

double	get_jy(int set)
{
	if (set == 1)
		return (0.1);
	else if (set == 2)
		return (0);
	else if (set == 3)
		return (0.01);
	else if (set == 4)
		return (0.1428);
	else if (set == 5)
		return (-0.3842);
	else if (set == 6)
		return (-0.2321);
	else if (set == 7)
		return (0.156);
	else if (set == 8)
		return (0.1889);
	else
		return (-0.8);
}

double	get_jx(int set)
{
	if (set == 1)
		return (-1.0);
	else if (set == 2)
		return (0.285);
	else if (set == 3)
		return (0.285);
	else if (set == 4)
		return (0.45);
	else if (set == 5)
		return (-0.70176);
	else if (set == 6)
		return (-0.835);
	else if (set == 7)
		return (-0.8);
	else if (set == 8)
		return (-0.7269);
	else
		return (0);
}

int	julia(double a, double b, t_data *data)
{
	double	tmp;
	double	real;
	double	img;
	int		i;

	real = (a * a) - (b * b) + get_jx(data->julia);
	img = (2 * a * b) + get_jy(data->julia);
	i = 0;
	while ((real * real) + (img * img) < 4)
	{
		tmp = real;
		real = (real * real) - (img * img) + get_jx(data->julia);
		img = (2 * tmp * img) + get_jy(data->julia);
		i++;
		if (i >= data->stb_lim)
			break ;
	}
	return (i);
}

int	mandelbrot(double a, double b, t_data *data)
{
	double	tmp;
	double	real;
	double	img;
	int		i;

	real = (a * a) - (b * b) + a;
	img = (2 * a * b) + b;
	i = 0;
	while ((real * real) + (img * img) < 4)
	{
		tmp = real;
		real = (real * real) - (img * img) + a;
		img = (2 * tmp * img) + b;
		if (i >= data->stb_lim)
			break ;
		i++;
	}
	return (i);
}
