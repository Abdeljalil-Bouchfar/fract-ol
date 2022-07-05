/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:50:04 by abouchfa          #+#    #+#             */
/*   Updated: 2022/07/05 05:59:12 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validate_input(int ac, char **av)
{
	if (ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
		return (1);
	if (ac == 3 && !ft_strcmp(av[1], "Julia") && ft_atoi(av[2]) <= 9
		&& ft_atoi(av[2]) >= 1)
		return (2);
	else
	{
		ft_putstr("   Usage:\n");
		ft_putstr(" ./fractol Mandelbrot\n");
		ft_putstr(" ./fractol Julia SET_NB[1-9]\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.set = validate_input(ac, av);
	if (data.set == 2)
		data.julia = ft_atoi(av[2]);
	data.zoom = 2.0;
	data.stb_lim = 50;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1000, 1000, "Fract-ol");
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	draw(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0L, destroy_ntv, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
}
