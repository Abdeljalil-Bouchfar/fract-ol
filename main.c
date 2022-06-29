/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:50:04 by abouchfa          #+#    #+#             */
/*   Updated: 2022/06/27 18:58:52 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int    get_color(int it)
{
    uint8_t    rgb[3];
    double    div;

    div = (double)it / (double)50;
    rgb[0] = 9 * (1 - div) * pow(div, 3) * 255;
    rgb[1] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
    rgb[2] = 9 * pow((1 - div), 3) * div * 255;
    return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
// this function return if a number is stable or not
int julia(float a, float b, float j)
{
	int i = 0;
	float tmp;
	// float x = a;
	// float y = b;
	float real = (a * a) - (b * b);
	float img = (2 * a * b) + j;
	while ((real * real) + (img * img) < 4)
	{
		tmp = real;
		real = (real * real) - (img * img);
		img = (2 * tmp * img) + j;
		if (i >= 50)
			break;
		i++;
	}
	return i;
}

int mandelbrot(float a, float b)
{
	int i = 0;
	float tmp;
	float x = a;
	float y = b;
	float real = (a * a) - (b * b) + x;
	float img = (2 * a * b) + y;
	while ((real * real) + (img * img) < 4)
	{
		tmp = real;
		real = (real * real) - (img * img) + x;
		img = (2 * tmp * img) + y;
		if (i >= 50)
			break;
		i++;
	}
	return i;
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	float a;
	float b;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Fract-ol");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	int x = -1;
	while (++x < 1000)
	{
		int y = -1;
		while (++y < 1000)
		{
			a = (x * 0.004) - 2;
			b = ((y * 0.004) - 2) * -1;
			int iter = julia(a, b, 1);
			my_mlx_pixel_put(&img, x, y, get_color(iter));
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
