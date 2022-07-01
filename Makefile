# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 15:50:06 by abouchfa          #+#    #+#              #
#    Updated: 2022/06/29 17:28:34 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = cc -Wall -Wextra -Werror

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFILE = main.c \
		utils/ft_strcmp.c

all : $(NAME)

$(NAME) : $(CFILE)
	$(CFLAGS) $(CFILE) -L $(MLX) -o $(NAME)

clean :
	rm -f $(NAME)

re : clean all