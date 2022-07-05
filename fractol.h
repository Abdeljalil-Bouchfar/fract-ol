/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 05:18:43 by abouchfa          #+#    #+#             */
/*   Updated: 2022/07/05 06:09:25 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct s_data {
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		set;
	int		stb_lim;
	int		julia;
	double	zoom;
}				t_data;

void	draw(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	ft_putstr(char *s);

int		get_color(int it, t_data *data);
int		julia(double a, double b, t_data *data);
int		mandelbrot(double a, double b, t_data *data);

int		destroy_ntv(t_data *data);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);

#endif