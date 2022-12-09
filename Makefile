# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:38:03 by rburgsta          #+#    #+#              #
#    Updated: 2022/11/27 22:25:42 by rburgsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

#GL_INC = "/Users/$(USER)/.brew/opt/glfw/lib/"
FLAGS = -Wall -Wextra -Werror

FT_PATH = libft
LIBFT_INC = $(FT_PATH)
MLX_PATH = MLX42
MLX_INC = $(MLX_PATH)/include/MLX42

SRC = main.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	make -C $(FT_PATH)
	cc $(FLAGS) -o $(NAME) $(OBJ) -L$(MLX_PATH) -lmlx42 -L$(FT_PATH) -lft -lglfw -ldl

%.o: %.c
	cc -c $(FLAGS) -I$(MLX_INC) -I$(LIBFT_INC) $^ 

clean :
	make -C $(MLX_PATH) clean
	make -C $(FT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(MLX_PATH) fclean
	make -C $(FT_PATH) fclean
	rm -f $(NAME)

re: fclean all
