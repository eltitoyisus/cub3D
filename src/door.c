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

void	load_door(t_mlx_game *game)
{
	load_xpm(game, &game->door_close, "./sprites/door_close.xpm");
	if (game->door_close.img_ptr)
		printf("Door closed\n");
	else
		printf("Fail load texture\n");
}

int	is_near_door(t_game *game, int map_x, int map_y)
{
	double	distance;
	double	dx;
	double	dy;

	dx = game->player.pos_x - (map_x + 0.5);
	dy = game->player.pos_y - (map_y + 0.5);
	distance = sqrt(dx * dx + dy * dy);
	return (distance < DOOR_DISTANCE);
}

bool	check_door_at_position(t_mlx_game *game, int x, int y)
{
	if (y >= 0 && x >= 0 && y < game->map.height && x < game->map.width)
	{
		if (game->map.grid[y][x] == 'D' && is_near_door(game->game, x, y))
		{
			game->map.grid[y][x] = '0';
			game->door_toggle = true;
			return (true);
		}
	}
	return (false);
}

void	check_door_interaction(t_mlx_game *game)
{
	bool	found_nearby_door;
	int		x;
	int		y;
	int		player_x;
	int		player_y;

	found_nearby_door = false;
	if (!game || !game->game)
		return ;
	player_x = (int)game->game->player.pos_x;
	player_y = (int)game->game->player.pos_y;
	y = player_y - 1.75;
	while (y <= player_y + 1.75 && !found_nearby_door)
	{
		x = player_x - 1.75;
		while (x <= player_x + 1.75 && !found_nearby_door)
		{
			if (check_door_at_position(game, x, y))
				found_nearby_door = true;
			x++;
		}
		y++;
	}
	if (!found_nearby_door)
		game->door_toggle = false;
}

int	handle_doors(t_mlx_game *game)
{
	check_door_interaction(game);
	return (0);
}
