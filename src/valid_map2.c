/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:20:46 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/20 17:20:46 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	valid_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	valid_char(char c)
{
	return (c == '0' || c == 'D' || c == '1' || c == ' ' || valid_player(c));
}

int	valid_map_chars(char **grid, int width, int height)
{
	int	i;
	int	j;

	if (!grid)
		return (0);
	i = 0;
	while (i < height)
	{
		j = 0;
		if (!grid[i])
			return (printf("Error: Invalid map row\n"), 0);
		while (j < width && grid[i][j])
		{
			if (!valid_char(grid[i][j]))
				return (printf("Error: Invalid character\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	set_player(t_game *game, int x, int y, char dir)
{
	game->map.player_pos.x = x;
	game->map.player_pos.y = y;
	game->map.player_dir = dir;
}

int	find_player_position(t_game *game)
{
	int		i;
	char	**grid;
	int		j;

	i = 0;
	grid = game->map.grid;
	if (!grid || game->map.height <= 0)
		return (0);
	while (i < game->map.height)
	{
		j = 0;
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
