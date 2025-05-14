# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 20:02:00 by jramos-a          #+#    #+#              #
#    Updated: 2025/05/14 12:47:28 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wall -Wextra -g3 # -lm for math
MLXFLAGS = -lm -lX11 -lXext
NAME = cub3D
RM = rm -rf
SRC_DIR = src/

SRC = $(SRC_DIR)main.c				\
		$(SRC_DIR)valid_arg.c		\
		$(SRC_DIR)valid_sprite.c	\
		$(SRC_DIR)valid_rgb.c		\
		$(SRC_DIR)valid_map.c		\
		$(SRC_DIR)player_pos.c		\
		$(SRC_DIR)utils.c			\
		$(SRC_DIR)init_struct.c		\
		$(SRC_DIR)handle_movement.c	\
		$(SRC_DIR)handle_mouse.c	\
		$(SRC_DIR)save_params.c		\
		$(SRC_DIR)read_file.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

minilibx/libmlx.a:
	@$(MAKE) -C minilibx

$(NAME): $(OBJ) libft/libft.a minilibx/libmlx.a
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a minilibx/libmlx.a $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C minilibx

fclean:
	@$(RM) $(OBJ) $(NAME)

re: fclean all

v: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re
