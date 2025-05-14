/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:20:32 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/10 12:00:00 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init_game(t_game *game)
{
	if (!game)
		return;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player_pos.x = -1;
	game->map.player_pos.y = -1;
	game->map.player_dir = '\0';
	game->map.valid = 0;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_r = -1;
	game->floor_g = -1;
	game->floor_b = -1;
	game->ceiling_r = -1;
	game->ceiling_g = -1;
	game->ceiling_b = -1;
}

int	valid_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || valid_player(c));
}

void	set_player(t_game *game, int x, int y, char dir)
{
	game->map.player_pos.x = x;
	game->map.player_pos.y = y;
	game->map.player_dir = dir;
}

int find_player_position(t_game *game)
{
	int i = 0;
	char **grid = game->map.grid;

	if (!grid || game->map.height <= 0)
		return (0);
	while (i < game->map.height)
	{
		int j = 0;
		while (grid[i][j])
		{
			if (valid_player(grid[i][j]))
			{
				set_player(game, j, i, grid[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	map_cpy(char **src, char **dest, int width, int height)
{
	int i = 0;
	int j = 0;
	(void)src;

	dest = malloc(sizeof(char *) * height);
	if (!dest)
		return;
	while (i < height)
	{
		dest[i] = malloc(sizeof(char) * (width + 1));
		if (!dest[i])
		{
			while (i > 0)
			{
				free(dest[i - 1]);
				i--;
			}
			free(dest);
			return;
			j++;
		}
		i++;
	}
}

void flood_fill(t_game *game, char **grid, int x, int y, int width, int height, int *map_breached)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		*map_breached = 1;
		return;
	}
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return;
	grid[y][x] = 'V';
	flood_fill(game, grid, x + 1, y, width, height, map_breached);
	flood_fill(game, grid, x - 1, y, width, height, map_breached);
	flood_fill(game, grid, x, y + 1, width, height, map_breached);
	flood_fill(game, grid, x, y - 1, width, height, map_breached);
}

int valid_map(t_game *game)
{
	int width = game->map.width;
	int height = game->map.height;
	char **grid = game->map.grid;
	char **temp_grid;
	int i = 0;
	static int map_breached = 0;

	if (!grid || width <= 0 || height <= 0)
	{
		game->map.valid = 0;
		return (0);
	}
	if (!find_player_position(game))
	{
		game->map.valid = 0;
		return (0);
	}
	temp_grid = malloc(sizeof(char *) * (height + 1));
	if (!temp_grid)
		return (0);
	while (i < height)
	{
		temp_grid[i] = ft_strdup(grid[i]);
		if (!temp_grid[i])
		{
			while (--i >= 0)
				free(temp_grid[i]);
			free(temp_grid);
			return (0);
		}
		i++;
	}
	temp_grid[height] = NULL;
	int x = game->map.player_pos.x;
	int y = game->map.player_pos.y;
	map_breached = 0;
	flood_fill(game, temp_grid, x, y, width, height, &map_breached);
	while (i < height)
		free(temp_grid[i++]);
	free(temp_grid);
	if (map_breached)
		return (game->map.valid = 0, 0);
	return (1);
}
