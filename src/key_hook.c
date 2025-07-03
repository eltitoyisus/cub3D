/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:55:53 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 16:55:53 by jramos-a         ###   ########.fr       */
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

void	init_movement(t_mlx_game *game)
{
	game->input.move_forward = 0;
	game->input.move_backward = 0;
	game->input.move_left = 0;
	game->input.move_right = 0;
	game->input.turn_left = 0;
	game->input.turn_right = 0;
}

int	key_press(int keycode, t_mlx_game *game)
{
	if (keycode == KEY_W)
		game->input.move_forward = 1;
	if (keycode == KEY_S)
		game->input.move_backward = 1;
	if (keycode == KEY_A)
		game->input.move_left = 1;
	if (keycode == KEY_D)
		game->input.move_right = 1;
	if (keycode == LOOK_LEFT)
		game->input.turn_left = 1;
	if (keycode == LOOK_RIGHT)
		game->input.turn_right = 1;
	if (keycode == KEY_ESC)
		handle_exit(game);
	return (0);
}

int	key_release(int keycode, t_mlx_game *game)
{
	if (keycode == KEY_W)
		game->input.move_forward = 0;
	if (keycode == KEY_S)
		game->input.move_backward = 0;
	if (keycode == KEY_A)
		game->input.move_left = 0;
	if (keycode == KEY_D)
		game->input.move_right = 0;
	if (keycode == LOOK_LEFT)
		game->input.turn_left = 0;
	if (keycode == LOOK_RIGHT)
		game->input.turn_right = 0;
	return (0);
}
