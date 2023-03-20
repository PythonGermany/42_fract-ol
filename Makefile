# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:38:03 by rburgsta          #+#    #+#              #
#    Updated: 2023/03/20 17:25:01 by rburgsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GL_INC = "/Users/$(USER)/.brew/opt/glfw/lib/"
FLAGS = -Wall -Wextra -Werror

FT_PATH = libft
LIBFT_INC = $(FT_PATH)
MLX_PATH = MLX42
MLX_INC = $(MLX_PATH)/include/MLX42
CMAKE_TRD = -j$(shell sysctl -a | grep machdep.cpu.thread | awk '{print $$2}')

SRC = main.c fractals.c colors.c hooks.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	cmake -S $(MLX_PATH) -B $(MLX_PATH)/build
	make -C $(MLX_PATH)/build $(CMAKE_TRD)
	make -C $(FT_PATH)
	cc $(FLAGS) -o $(NAME) $(OBJ) -L$(MLX_PATH)/build -lmlx42 -L$(FT_PATH) -lft -L$(GL_INC) -lglfw -ldl

gen : fract-gen.o fractals.o colors.o
	make -C $(FT_PATH)
	cc $(FLAGS) -o fract-gen $? -L$(FT_PATH) -lft

%.o: %.c
	cc -c $(FLAGS) -I$(MLX_INC) -I$(LIBFT_INC) $^ 

clean :
	rm -rf $(MLX_PATH)/build
	make -C $(FT_PATH) clean
	rm -f $(OBJ)
	rm -f fract-gen.o

fclean: clean
	rm -f $(NAME)
	rm -f fract-gen

re: fclean all
