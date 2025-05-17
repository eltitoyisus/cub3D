/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:12:30 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/17 23:12:30 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

// #define DOOR_DISTANCE 2.0

// void load_door(t_mlx_game *game)
// {
// 	game->game->door_open = "./sprites/door_open.xpm";
// 	game->game->door_close = "./sprites/door_close.xpm";
// 	load_xpm(game, &game->door_open, game->game->door_open);
// 	load_xpm(game, &game->door_close, game->game->door_close);
// }

// int is_near_door(t_game *game, int map_x, int map_y)
// {
// 	double distance;
// 	double dx;
// 	double dy;

// 	dx = game->player.pos_x - (map_x + 0.5);
// 	dy = game->player.pos_y - (map_y + 0.5);
// 	distance = sqrt(dx * dx + dy * dy);
// 	return (distance < DOOR_DISTANCE);
// }

// void check_door_interaction(t_mlx_game *game)
// {
// 	t_mlx_game *current_texture;

// 	int map_x = (int)game->player.pos_x;
// 	int map_y = (int)game->player.pos_y;
// 	if (game->map.grid[map_y][map_x] == 'D')
// 	{
// 		if (is_near_door(game, map_x, map_y))
// 		{
// 			if (game->door_open.img_ptr)
// 				current_texture = &game->door_open;
// 			else
// 				current_texture = &game->door_close;
// 			load_xpm(game, current_texture, current_texture->img_ptr);
// 		}
// 	}
// }

// int handle_doors(t_mlx_game *game)
// {
// 	check_door_interaction(game);
// 	return (0);
// }
