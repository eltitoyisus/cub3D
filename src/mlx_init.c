/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:28 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/15 09:12:28 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int ft_init(t_mlx_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return 1;
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		ft_destroy(game->mlx);
	init_textures(game);
	mlx_key_hook(game->win, key_handle, game);
	// mlx_mouse_hide(game->mlx, game->win);
	// mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	mlx_loop(game->mlx);
	return 0;
}

void ft_destroy(t_mlx_game *game)
{
	if (game->no_tex.img_ptr)
		mlx_destroy_image(game.mlx, game->no_tex.img_ptr);
	if (game->so_tex.img_ptr)
		mlx_destroy_image(game.mlx, game->so_tex.img_ptr);
	if (game->we_tex.img_ptr)
		mlx_destroy_image(game.mlx, game->we_tex.img_ptr);
	if (game->ea_tex.img_ptr)
		mlx_destroy_image(game.mlx, game->ea_tex.img_ptr);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}
