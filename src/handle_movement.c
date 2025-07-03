/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:31:17 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 16:56:19 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

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

void	process_input(t_mlx_game *game)
{
	if (game->input.move_forward)
		move_forward(game->game);
	if (game->input.move_backward)
		move_backward(game->game);
	if (game->input.move_left)
		move_left(game->game);
	if (game->input.move_right)
		move_right(game->game);
	if (game->input.turn_left)
		rotate_left(game->game);
	if (game->input.turn_right)
		rotate_right(game->game);
}
