/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:31:37 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/04 12:23:42 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

// int	toggle_mouse_visibility(t_mlx_game *mlx_game, int show)
// {
// 	if (!mlx_game || !mlx_game->mlx || !mlx_game->win)
// 		return (0);
// 	if (show)
// 		mlx_mouse_show(mlx_game->mlx, mlx_game->win);
// 	else
// 		mlx_mouse_hide(mlx_game->mlx, mlx_game->win);
// 	return (1);
// }

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(-MOUSE_SPEED) - game->player.dir_y
		* sin(-MOUSE_SPEED);
	game->player.dir_y = old_dir_x * sin(-MOUSE_SPEED) + game->player.dir_y
		* cos(-MOUSE_SPEED);
	game->player.plane_x = old_plane_x * cos(-MOUSE_SPEED)
		- game->player.plane_y * sin(-MOUSE_SPEED);
	game->player.plane_y = old_plane_x * sin(-MOUSE_SPEED)
		+ game->player.plane_y * cos(-MOUSE_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(MOUSE_SPEED) - game->player.dir_y
		* sin(MOUSE_SPEED);
	game->player.dir_y = old_dir_x * sin(MOUSE_SPEED) + game->player.dir_y
		* cos(MOUSE_SPEED);
	game->player.plane_x = old_plane_x * cos(MOUSE_SPEED) - game->player.plane_y
		* sin(MOUSE_SPEED);
	game->player.plane_y = old_plane_x * sin(MOUSE_SPEED) + game->player.plane_y
		* cos(MOUSE_SPEED);
}

int	handle_mouse(int x, int y, t_mlx_game *mlx_game)
{
	t_game	*game;

	game = mlx_game->game;
	if (y > HEIGHT - 20)
	{
		mlx_mouse_hide(mlx_game->mlx, mlx_game->win);
		mlx_mouse_move(mlx_game->mlx, mlx_game->win, WIDTH / 2, HEIGHT / 2);
	}
	if (x < WIDTH / 2)
	{
		mlx_mouse_hide(mlx_game->mlx, mlx_game->win);
		rotate_left(game);
		mlx_mouse_move(mlx_game->mlx, mlx_game->win, WIDTH / 2, HEIGHT / 2);
	}
	else if (x > WIDTH / 2)
	{
		mlx_mouse_hide(mlx_game->mlx, mlx_game->win);
		rotate_right(game);
		mlx_mouse_move(mlx_game->mlx, mlx_game->win, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}
