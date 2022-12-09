# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:38:03 by rburgsta          #+#    #+#              #
#    Updated: 2022/11/25 16:39:19 by rburgsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GL_INC = "/Users/$(USER)/.brew/opt/glfw/lib/"
FLAGS = -Wall -Wextra -Werror

FT_PATH = libft
LIBFT_INC = $(FT_PATH)/includes
MLX_PATH = MLX42
MLX_INC = $(MLX_PATH)/include/MLX42

SRC = main.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	make -C $(FT_PATH)
	cc $(FLAGS) -o $(NAME) $(OBJ) -L$(MLX_PATH) -lmlx42 -L$(FT_PATH) -lft -L$(GL_INC) -lglfw

%.o: %.c
	cc $(FLAGS) -I$(MLX_INC) -I$(LIBFT_INC) -c $< -o $@ 

clean :
	make -C $(MLX_PATH) clean
	make -C $(FT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(MLX_PATH) fclean
	make -C $(FT_PATH) fclean
	rm -f $(NAME)

re: fclean all
