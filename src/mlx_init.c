/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:28 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/16 12:41:55 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void init_textures(t_mlx_game *game)
{
	int width;
	int height;
	
	game->no_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->game->no_texture, &width, &height);
	if (game->no_tex.img_ptr)
	{
		game->no_tex.width = width;
		game->no_tex.height = height;
		game->no_tex.addr = mlx_get_data_addr(game->no_tex.img_ptr, &game->no_tex.bits_per_pixel,
											&game->no_tex.line_length, &game->no_tex.endian);
	}
	game->so_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->game->so_texture, &width, &height);
	if (game->so_tex.img_ptr)
	{
		game->so_tex.width = width;
		game->so_tex.height = height;
		game->so_tex.addr = mlx_get_data_addr(game->so_tex.img_ptr, &game->so_tex.bits_per_pixel,
											&game->so_tex.line_length, &game->so_tex.endian);
	}
	game->ea_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->game->ea_texture, &width, &height);
	if (game->ea_tex.img_ptr)
	{
		game->ea_tex.width = width;
		game->ea_tex.height = height;
		game->ea_tex.addr = mlx_get_data_addr(game->ea_tex.img_ptr, &game->ea_tex.bits_per_pixel,
											&game->ea_tex.line_length, &game->ea_tex.endian);
	}
	game->we_tex.img_ptr = mlx_xpm_file_to_image(game->mlx, game->game->we_texture, &width, &height);
	if (game->we_tex.img_ptr)
	{
		game->we_tex.width = width;
		game->we_tex.height = height;
		game->we_tex.addr = mlx_get_data_addr(game->we_tex.img_ptr, &game->we_tex.bits_per_pixel,
											&game->we_tex.line_length, &game->we_tex.endian);
	}
}

int render_frame(void *param)
{
	t_mlx_game *game = (t_mlx_game *)param;
	
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr, &game->img.bits_per_pixel, 
									&game->img.line_length, &game->img.endian);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
	game->img.img_ptr = NULL;
	game->img.addr = NULL;
	return (0);
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
	mlx_key_hook(game->win, key_handle, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return 0;
}

void ft_destroy(t_mlx_game *game)
{
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
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
