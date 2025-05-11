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
int valid_file_exists(char *path);
int valid_sprite(char *line);
int check_all_directions(char *input);

// VALID RGB
int valid_value(char *str);
int valid_rgb(char *line);
int valid_format(char *input);

// VALID MAP
// char	**create_visited(t_map map);
// void	do_flood_fill(t_map map, int x, int y, char **visited);
// int	check_boundaries(t_map map, char **visited);
// int	flood_fill(t_map map);
// t_map	parse_map_from_file(char *filename);
// int	playable_map(t_map map);
int	valid_map(char *filename);


// UTILS
void	free_arr(char **arr);
// void	free_visited(ch ar **visited, int height);
