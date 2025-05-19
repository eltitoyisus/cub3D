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

void load_door(t_mlx_game *game)
{
	load_xpm(game, &game->door_close, "./sprites/door_close.xpm");
	if (game->door_close.img_ptr)
		printf("Door closed\n");
	else
		printf("Fail load texture\n");
	load_xpm(game, &game->door_open, "./sprites/door_open.xpm");
}

int is_near_door(t_game *game, int map_x, int map_y)
{
	double distance;
	double dx;
	double dy;

	dx = game->player.pos_x - (map_x + 0.5);
	dy = game->player.pos_y - (map_y + 0.5);
	distance = sqrt(dx * dx + dy * dy);
	return (distance < DOOR_DISTANCE);
}

void check_door_interaction(t_mlx_game *game)
{
	int map_x, map_y;

	if (!game || !game->game)
		return;
	map_x = (int)game->game->player.pos_x;
	map_y = (int)game->game->player.pos_y;
	if (map_y < 0 || map_x < 0 || map_y >= game->map.height || map_x >= game->map.width)
		return;
	if (game->map.grid[map_y][map_x] == 'D')
	{
		if (is_near_door(game->game, map_x, map_y))
			game->door_toggle = !game->door_toggle;
	}
}

int handle_doors(t_mlx_game *game)
{
	check_door_interaction(game);
	return (0);
}
