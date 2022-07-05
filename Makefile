# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 15:50:06 by abouchfa          #+#    #+#              #
#    Updated: 2022/07/05 03:23:22 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = cc -Wall -Wextra -Werror

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFILE = fractol.c \
		utils/draw.c \
		utils/libft_funs.c \
		utils/maths.c \
		utils/hooks.c \

all : $(NAME)

$(NAME) : $(CFILE)
	$(CFLAGS) $(CFILE) -L $(MLX) -o $(NAME)

clean :
	rm -f $(NAME)

fclean:	clean

re : clean all