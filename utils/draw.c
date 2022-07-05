/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:15:51 by abouchfa          #+#    #+#             */
/*   Updated: 2022/07/05 05:59:32 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_data *data)
{
	int		stb_lim;
	int		x;
	int		y;
	double	a;
	double	b;

	x = -1;
	while (++x < 1000)
	{
		y = -1;
		while (++y < 1000)
		{
			a = (x * (0.002 * data->zoom)) - data->zoom;
			b = ((y * (0.002 * data->zoom)) - data->zoom) * -1;
			if (data->set == 1)
				stb_lim = mandelbrot(a, b, data);
			else if (data->set == 2)
				stb_lim = julia(a, b, data);
			my_mlx_pixel_put(data, x, y, get_color(stb_lim, data));
		}
	}
}
