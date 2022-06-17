# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 15:50:06 by abouchfa          #+#    #+#              #
#    Updated: 2022/06/17 05:55:45 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = cc -Wall -Wextra -Werror

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = main.c

all : $(NAME)

$(NAME) : $(SRCS)
	$(CFLAGS) $(SRCS) -L $(MLX) -o $(NAME)

clean :
	rm -f $(NAME)

re : clean all