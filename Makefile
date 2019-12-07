# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 13:54:08 by aszhilki          #+#    #+#              #
#    Updated: 2019/12/06 19:19:36 by aszhilki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra -g

SRC_NAME = main.c map.c keys.c draw.c
SRC_PATH = ./src/
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

MLX_PATH = ./minilibx/
MLX_LIB = ./minilibx/libmlx.a
MLX_LNK = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

LFT_PATH = ./libft/
LFT_LIB = ./libft/libft.a
LFT_LNK = -L ./libft -lft

all: $(NAME)

$(LFT_LIB):
	make -C $(LFT_PATH)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(NAME): $(LFT_LIB) $(MLX_LIB)
	gcc -o $(NAME) $(SRC) $(LFT_LNK) $(MLX_LNK) $(FLAGS)

clean:
	make -C $(LFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LFT_PATH) fclean

re: fclean all
