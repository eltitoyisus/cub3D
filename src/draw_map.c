/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:12:47 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/20 13:12:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	draw_ceiling_floor(t_mlx_game *game, int x, t_draw_data data)
{
	int	y;

	y = data.start;
	while (y < data.end)
	{
		my_mlx_pixel_put(&game->img, x, y, data.color);
		y++;
	}
}

t_texture	*select_texture(t_mlx_game *game)
{
	if (game->map.grid[game->ray.map_y][game->ray.map_x] == 'D')
	{
		if (game->door_toggle)
			return (&game->door_open);
		return (&game->door_close);
	}
	else if (game->ray.side == 0)
	{
		if (game->ray.step_x > 0)
			return (&game->ea_tex);
		return (&game->we_tex);
	}
	else
	{
		if (game->ray.step_y > 0)
			return (&game->so_tex);
		return (&game->no_tex);
	}
}

double	calculate_wall_x(t_mlx_game *game)
{
	double	wall_x;

	if (game->ray.side == 0)
		wall_x = game->ray.pos_y + game->ray.perp_wall_dist * game->ray.dir_y;
	else
		wall_x = game->ray.pos_x + game->ray.perp_wall_dist * game->ray.dir_x;
	return (wall_x - floor(wall_x));
}

void	draw_texture_pixel(t_mlx_game *game, int x, int y, t_texture *texture)
{
	int		coords[2];
	char	*pixel;
	int		color;

	get_texture_coords(game, texture, y, coords);
	if (texture && texture->addr && coords[0] >= 0 && coords[0] < texture->width
		&& coords[1] >= 0 && coords[1] < texture->height)
	{
		pixel = texture->addr + (coords[1] * texture->line_length + coords[0]
				* (texture->bits_per_pixel / 8));
		color = *(unsigned int *)pixel;
		my_mlx_pixel_put(&game->img, x, y, color);
	}
}

void	draw_vertical_line(t_mlx_game *game, int x)
{
	t_texture	*current_texture;
	t_draw_data	ceiling;
	t_draw_data	floor;
	int			y;

	ceiling.start = 0;
	ceiling.end = game->ray.draw_start;
	ceiling.color = create_rgb(game->game->ceiling_r, game->game->ceiling_g,
			game->game->ceiling_b);
	floor.start = game->ray.draw_end;
	floor.end = HEIGHT;
	floor.color = create_rgb(game->game->floor_r, game->game->floor_g,
			game->game->floor_b);
	draw_ceiling_floor(game, x, ceiling);
	current_texture = select_texture(game);
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		draw_texture_pixel(game, x, y, current_texture);
		y++;
	}
	draw_ceiling_floor(game, x, floor);
}
