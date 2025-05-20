/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:15:06 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/19 19:15:06 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void draw_square(t_mlx_game *game, int x, int y, int color)
{
	int i;
	int j;
	int size;

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

void draw_player(t_mlx_game *game, int x, int y)
{
	int i;
	int j;
	int radius;
	
	radius = game->minimap.square_size / 3;
	if (radius < 3)
		radius = 3;
	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if ((i*i + j*j) <= (radius*radius))
			{
				if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT)
					my_mlx_pixel_put(&game->img, x + i, y + j, 0xFF0000);
			}
			j++;
		}
		i++;
	}
}

int minimap(t_mlx_game *game)
{
	int x;
	int y;
	int offset_x;
	int offset_y;
	int map_size;

	if (!game->img.img_ptr || !game->img.addr)
		return (1);
	map_size = game->minimap.square_size;
	offset_x = 10;
	offset_y = 10;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (!(x < 0 || y < 0 || x >= game->map.width || y >= game->map.height))
			{
				int draw_x = offset_x + (x * map_size);
				int draw_y = offset_y + (y * map_size);
				if (game->map.grid[y][x] == '1')
					draw_square(game, draw_x, draw_y, 0x888888);
				else if (game->map.grid[y][x] == '0' || game->map.grid[y][x] == 'D' || 
						game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S' || 
						game->map.grid[y][x] == 'E' || game->map.grid[y][x] == 'W')
					draw_square(game, draw_x, draw_y, 0x333333);
			}
			x++;
		}
		y++;
	}
	draw_player(game, 
				offset_x + (int)(game->ray.pos_x * map_size), 
				offset_y + (int)(game->ray.pos_y * map_size));
	return (0);
}
