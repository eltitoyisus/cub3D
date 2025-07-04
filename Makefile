# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 20:02:00 by jramos-a          #+#    #+#              #
#    Updated: 2025/07/04 17:32:47 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wall -Wextra -Ilibft -Iminilibx -g3
MLXFLAGS = -Lminilibx -lmlx -lXext -lX11 -lXfixes -lm
NAME = cub3D
RM = rm -rf
SRC_DIR = src/

SRC = $(SRC_DIR)main.c				\
		$(SRC_DIR)valid_arg.c		\
		$(SRC_DIR)valid_sprite.c	\
		$(SRC_DIR)valid_rgb.c		\
		$(SRC_DIR)valid_map.c		\
		$(SRC_DIR)valid_map2.c		\
		$(SRC_DIR)boundaries.c		\
		$(SRC_DIR)valid_map_utils.c	\
		$(SRC_DIR)player_pos.c		\
		$(SRC_DIR)utils.c			\
		$(SRC_DIR)key_hook.c		\
		$(SRC_DIR)init_struct.c		\
		$(SRC_DIR)init_game.c		\
		$(SRC_DIR)init_parse.c		\
		$(SRC_DIR)handle_movement.c	\
		$(SRC_DIR)handle_mouse.c	\
		$(SRC_DIR)save_params.c		\
		$(SRC_DIR)save_params2.c	\
		$(SRC_DIR)read_file.c		\
		$(SRC_DIR)read_file2.c		\
		$(SRC_DIR)read_file3.c		\
		$(SRC_DIR)read_file4.c		\
		$(SRC_DIR)mlx_init.c		\
		$(SRC_DIR)key_binds.c		\
		$(SRC_DIR)convert_xpm.c		\
		$(SRC_DIR)raycasting.c		\
		$(SRC_DIR)minimap.c			\
		$(SRC_DIR)draw_map.c		\
		$(SRC_DIR)draw_map2.c		\
		$(SRC_DIR)valid_player.c	\
		$(SRC_DIR)error.c			\
		$(SRC_DIR)door.c

OBJS = $(SRC:.c=.o)

all: $(NAME)


libft/libft.a:
	@$(MAKE) -C libft

minilibx/libmlx.a:
	@chmod 777 ./minilibx/configure
	@$(MAKE) -C minilibx

$(NAME): $(OBJS) libft/libft.a minilibx/libmlx.a
	@chmod 777 ./minilibx/configure
	@$(CC) $(FLAGS) $(OBJS) libft/libft.a minilibx/libmlx.a $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) 
	@ cd libft && make clean
	@ cd minilibx && make clean

fclean: clean
	@$(RM) $(NAME)
	@ cd libft && make fclean

re: fclean all
	@clear

v:
	@valgrind --suppressions=mlx.supp --track-origins=yes --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) maps/$(filter-out v,$(MAKECMDGOALS))

.PHONY: all clean fclean re v $(filter-out v clean fclean re all,$(MAKECMDGOALS))

%:
	@: