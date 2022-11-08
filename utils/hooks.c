/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:11:17 by abouchfa          #+#    #+#             */
/*   Updated: 2022/07/05 06:05:51 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	destroy_ntv(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if ((keycode == 126 || keycode == 124) && data->set == 2)
	{
		if (data->julia == 9)
			data->julia = 1;
		else
			data->julia += 1;
		draw(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if ((keycode == 125 || keycode == 123) && data->set == 2)
	{
		if (data->julia == 1)
			data->julia = 9;
		else
			data->julia -= 1;
		draw(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 53)
		destroy_ntv(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (keycode == 4)
	{
		data->zoom += (data->zoom / 10);
		if (data->stb_lim > 50)
			data->stb_lim -= 10;
		draw(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 5)
	{
		data->zoom -= (data->zoom / 10);
		data->stb_lim += 10;
		draw(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}
