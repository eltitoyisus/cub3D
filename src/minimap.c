/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:15:06 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 14:39:29 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	draw_square(t_mlx_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	size = game->minimap.square_size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT)
				my_mlx_pixel_put(&game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_mlx_game *game, int x, int y)
{
	int	i;
	int	j;
	int	radius;

	radius = game->minimap.square_size / 3;
	if (radius < 3)
		radius = 3;
	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if ((i * i + j * j) <= (radius * radius))
			{
				if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT)
					my_mlx_pixel_put(&game->img, x + i, y + j, 0xFF0000);
			}
			j++;
		}
		i++;
	}
}

void	draw_map_element(t_mlx_game *game, int x, int y, int map_size)
{
	int	draw_x;
	int	draw_y;

	draw_x = 10 + (x * map_size);
	draw_y = 10 + (y * map_size);
	if (game->map.grid[y][x] == '1')
		draw_square(game, draw_x, draw_y, 0x888888);
	else if (game->map.grid[y][x] == '0' || game->map.grid[y][x] == 'D'
		|| game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S'
		|| game->map.grid[y][x] == 'E' || game->map.grid[y][x] == 'W')
		draw_square(game, draw_x, draw_y, 0x333333);
}

int	render_minimap(t_mlx_game *game, int map_size)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (!(x < 0 || y < 0 || x >= game->map.width
					|| y >= game->map.height))
				draw_map_element(game, x, y, map_size);
			x++;
		}
		y++;
	}
	return (0);
}

int	minimap(t_mlx_game *game)
{
	int	map_size;
	int	offset_x;
	int	max_minimap_size;
	int	size_x;
	int	size_y;

	if (!game->img.img_ptr || !game->img.addr)
		return (1);
	max_minimap_size = 200;
	size_x = max_minimap_size / game->map.width;
	size_y = max_minimap_size / game->map.height;
	if (size_x < size_y)
		map_size = size_x;
	else
		map_size = size_y;
	if (map_size < 1)
		map_size = 1;
	game->minimap.square_size = map_size;
	offset_x = 10;
	render_minimap(game, map_size);
	draw_player(game, offset_x + (int)(game->ray.pos_x * map_size), 10
		+ (int)(game->ray.pos_y * map_size));
	return (0);
}
