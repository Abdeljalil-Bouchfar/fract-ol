/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:50:04 by abouchfa          #+#    #+#             */
/*   Updated: 2022/06/17 09:03:34 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fract-ol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int x = -1;
	while (++x < 1920)
	{
		int y = -1;
		while (++y < 1080)
		{
			if ((((x - 960) * (x - 960)) + ((y - 540) * (y - 540))) < 300 * 300)
				my_mlx_pixel_put(&img, x, y, 0x00ebe709);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// printf("%i\n", img.line_length);
	// printf("%i\n", img.bits_per_pixel);
	// printf("%i\n", img.endian);
	mlx_loop(mlx);
}
