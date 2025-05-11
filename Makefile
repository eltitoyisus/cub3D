# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 20:02:00 by jramos-a          #+#    #+#              #
#    Updated: 2025/05/10 12:48:54 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wall -Wextra -g3
NAME = cub3D
RM = rm -rf
SRC_DIR = src/

SRC = $(SRC_DIR)main.c				\
		$(SRC_DIR)valid_arg.c		\
		$(SRC_DIR)valid_sprite.c	\
		$(SRC_DIR)valid_rgb.c		\
		$(SRC_DIR)valid_map.c		\
		$(SRC_DIR)player_pos.c		\
		$(SRC_DIR)utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME) $(LDFLAGS)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C libft

fclean:
	@$(RM) $(OBJ) $(NAME)
	@$(MAKE) fclean -C libft

re: fclean all

v: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re
