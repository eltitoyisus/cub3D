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

void	flood_fill(char **grid, int x, int y, int width, int height)
{
	if (x < 0 || y < 0 || y >= height || x >= width)
		return;
	if (grid[y][x] != '0' && !valid_player(grid[y][x]))
		return;
	grid[y][x] = 'F';
	flood_fill(grid, x + 1, y, width, height);
	flood_fill(grid, x - 1, y, width, height);
	flood_fill(grid, x, y + 1, width, height);
	flood_fill(grid, x, y - 1, width, height);
}

int	valid_map(t_game *game)
{
	(void)game;
}
