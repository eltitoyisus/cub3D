/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/21 10:25:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	handle_exit(void *param)
{
	t_mlx_game	*game;

	game = (t_mlx_game *)param;
	ft_destroy(game);
	exit(0);
	return (0);
}

int	ft_look(int keycode, t_game *game)
{
	if (keycode == LOOK_LEFT)
		rotate_left(game);
	else if (keycode == LOOK_RIGHT)
		rotate_right(game);
	return (0);
}

int	ft_movement(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	return (0);
}

int	key_handle(int keycode, void *param)
{
	t_mlx_game	*mlx_game;
	t_game		*game;

	mlx_game = (t_mlx_game *)param;
	game = mlx_game->game;
	if (keycode == LOOK_RIGHT || keycode == LOOK_LEFT)
		ft_look(keycode, game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		ft_movement(keycode, game);
	else if (keycode == KEY_ESC)
		handle_exit(mlx_game);
	return (0);
}
