/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:28 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/18 19:33:59 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int render_frame(void *param)
{
	t_mlx_game *game = (t_mlx_game *)param;

	if (!game || !game->mlx)
		return (1);
	handle_doors(game);
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		return (1);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr, &game->img.bits_per_pixel, 
									&game->img.line_length, &game->img.endian);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
	game->img.img_ptr = NULL;
	game->img.addr = NULL;
	return (0);
}

void ft_destroy(t_mlx_game *game)
{
	if (!game || !game->mlx)
		return;
	if (game->win)
			mlx_mouse_show(game->mlx, game->win);
	if (game->no_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->no_tex.img_ptr);
	if (game->so_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->so_tex.img_ptr);
	if (game->we_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->we_tex.img_ptr);
	if (game->ea_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->ea_tex.img_ptr);
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->door_open.img_ptr)
		mlx_destroy_image(game->mlx, game->door_open.img_ptr);
	if (game->door_close.img_ptr)
		mlx_destroy_image(game->mlx, game->door_close.img_ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int ft_init(t_mlx_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return 1;
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return 1;
	}
	game->img.img_ptr = NULL;
	game->img.addr = NULL;
	init_textures(game);
	init_mouse(game);
	mlx_hook(game->win, 2, 1L<<0, key_handle, game);
	mlx_hook(game->win, 6, 1L<<6, handle_mouse, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return 0;
}
