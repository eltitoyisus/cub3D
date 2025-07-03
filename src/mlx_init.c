/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:28 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 16:58:16 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	save_params(t_game *game, char **lines)
{
	if (!save_rgb(game, lines))
		return (0);
	if (!save_textures(game, lines))
		return (0);
	return (1);
}

void	raycasting(t_mlx_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		calculate_ray_position_and_direction(game, x);
		calculate_step_and_side_dist(game);
		perform_dda(game);
		calculate_wall_distance_and_height(game);
		draw_vertical_line(game, x);
		x++;
	}
}

int	render_frame(void *param)
{
	t_mlx_game	*game;

	game = (t_mlx_game *)param;
	if (!game || !game->mlx)
		return (1);
	handle_doors(game);
	process_input(game);
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		return (1);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	raycasting(game);
	minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
	game->img.img_ptr = NULL;
	game->img.addr = NULL;
	return (0);
}

void	ft_destroy(t_mlx_game *mlx_game)
{
	if (mlx_game->no_tex.img_ptr)
		mlx_destroy_image(mlx_game->mlx, mlx_game->no_tex.img_ptr);
	if (mlx_game->so_tex.img_ptr)
		mlx_destroy_image(mlx_game->mlx, mlx_game->so_tex.img_ptr);
	if (mlx_game->we_tex.img_ptr)
		mlx_destroy_image(mlx_game->mlx, mlx_game->we_tex.img_ptr);
	if (mlx_game->ea_tex.img_ptr)
		mlx_destroy_image(mlx_game->mlx, mlx_game->ea_tex.img_ptr);
	if (mlx_game->door_close.img_ptr)
		mlx_destroy_image(mlx_game->mlx, mlx_game->door_close.img_ptr);
	if (mlx_game->win)
		mlx_destroy_window(mlx_game->mlx, mlx_game->win);
	if (mlx_game->mlx)
	{
		mlx_destroy_display(mlx_game->mlx);
		mlx_loop_end(mlx_game->mlx);
		free(mlx_game->mlx);
	}
}

int	ft_init(t_mlx_game *game)
{
	init_movement(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (1);
	}
	game->img.img_ptr = NULL;
	game->img.addr = NULL;
	init_textures(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 6, 1L << 6, handle_mouse, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return (0);
}
