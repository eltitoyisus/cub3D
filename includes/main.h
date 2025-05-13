/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:55:08 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 08:55:08 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include "struct.h"

// PARSE
// VALID INPUT
int valid_ext(char *filename);
int valid_route(char *filename);
int valid_arg(char *filename);

// VALID SPRITES
int valid_coordinate(char *coordinate);
int valid_folder(char *filename);
int valid_sprite(char *line);

// VALID RGB
int valid_value(char *str);
int valid_rgb(char *line);
int valid_format(char *input);

// VALID MAP
int	valid_player(char c);
int valid_char(char c);
void set_player(t_game *game, int x, int y, char dir);
void flood_fill(char **grid, int x, int y, int width, int height);
int	valid_map(t_game *game);

// UTILS
void	free_arr(char **arr);
char *skip_white_spaces(char *line);


// EXEC
