/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 05:18:43 by abouchfa          #+#    #+#             */
/*   Updated: 2022/06/27 17:52:35 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>
# include <mlx.h>

# define BLACK 0x000000
# define BLUE 0x032BA5
# define YELLEW 0xabc912
# define GREEN 0x18a83e
# define RED 0xa81837

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif