/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:31:17 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/20 16:55:45 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	is_wall(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_x < 0 || map_y >= map->height || map_x >= map->width)
		return (1);
	return (map->grid[map_y][map_x] == '1');
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	if (!is_wall(&game->map, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(&game->map, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	if (!is_wall(&game->map, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(&game->map, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.plane_y * MOVE_SPEED;
	if (!is_wall(&game->map, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(&game->map, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.plane_y * MOVE_SPEED;
	if (!is_wall(&game->map, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(&game->map, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}
