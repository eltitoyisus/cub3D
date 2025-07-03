/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:02:59 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 16:30:44 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	my_mlx_pixel_put(t_texture *texture, int x, int y, int color)
{
	char	*dst;

	if (!texture || !texture->addr)
		return ;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = texture->addr + (y * texture->line_length + x
				* (texture->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	calculate_ray_position_and_direction(t_mlx_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	game->ray.dir_x = game->game->player.dir_x + game->game->player.plane_x
		* camera_x;
	game->ray.dir_y = game->game->player.dir_y + game->game->player.plane_y
		* camera_x;
	game->ray.pos_x = game->game->player.pos_x;
	game->ray.pos_y = game->game->player.pos_y;
	game->ray.map_x = (int)game->ray.pos_x;
	game->ray.map_y = (int)game->ray.pos_y;
	game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
	game->ray.hit = 0;
}

void	calculate_step_and_side_dist(t_mlx_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->ray.pos_x - game->ray.map_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->ray.pos_x)
			* game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->ray.pos_y - game->ray.map_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->ray.pos_y)
			* game->ray.delta_dist_y;
	}
}

void	perform_dda(t_mlx_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->ray.map_y >= 0 && game->ray.map_x >= 0
			&& game->ray.map_y < game->map.height
			&& game->ray.map_x < game->map.width
			&& game->map.grid[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
		if (game->ray.map_y >= 0 && game->ray.map_x >= 0
			&& game->ray.map_y < game->map.height
			&& game->ray.map_x < game->map.width
			&& game->map.grid[game->ray.map_y][game->ray.map_x] == 'D')
			game->ray.hit = 1;
	}
}

void	calculate_wall_distance_and_height(t_mlx_game *game)
{
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = (game->ray.map_x - game->ray.pos_x + (1
					- game->ray.step_x) / 2) / game->ray.dir_x;
	else
		game->ray.perp_wall_dist = (game->ray.map_y - game->ray.pos_y + (1
					- game->ray.step_y) / 2) / game->ray.dir_y;
	if (game->ray.perp_wall_dist < 0.1)
		game->ray.perp_wall_dist = 0.1;
	game->ray.line_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	game->ray.draw_start = -game->ray.line_height / 2 + HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + HEIGHT / 2;
	if (game->ray.draw_end >= HEIGHT)
		game->ray.draw_end = HEIGHT - 1;
}
