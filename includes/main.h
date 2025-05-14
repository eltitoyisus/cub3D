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
void	init_game(t_game *game);
int	valid_player(char c);
int valid_char(char c);
void set_player(t_game *game, int x, int y, char dir);
int find_player_position(t_game *game);
void map_cpy(char **src, char **dest, int width, int height);
void flood_fill(t_game *game, char **grid, int x, int y, int width, int height, int *map_breached);
int valid_map(t_game *game);

// READ FILE
int	process_config_line(char *clean_line, int fd, char *line):
int parse_file_content(int fd, t_game *game, char *map_lines[1000]);
int build_game_map(t_game *game, char **map_lines, int map_count);
int validate_game_map(t_game *game);
int is_valid_map_line(char *line);
int read_file(char *filepath);

// UTILS
void	free_arr(char **arr);
char *skip_white_spaces(char *line);
void	init_game(t_game *game);
int is_valid_map_line(char *line);
int build_game_map(t_game *game, char **map_lines, int map_count);
char *clean_line_str(char *line);


// EXEC
