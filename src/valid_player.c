/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:17:03 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 09:17:03 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	count_player_positions(t_game *game, char **grid, int *player_count)
{
	int	i;
	int	j;

	i = 0;
	*player_count = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (grid[i][j])
		{
			if (valid_player(grid[i][j]))
			{
				if (*player_count == 0)
					set_player(game, j, i, grid[i][j]);
				(*player_count)++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player_count(int player_count)
{
	if (player_count == 0)
		return (printf("Error: No player position found\n"), 0);
	if (player_count > 1)
		return (printf("Error: Multiple player positions found\n"), 0);
	return (1);
}

int	find_player_position(t_game *game)
{
	char	**grid;
	int		player_count;

	grid = game->map.grid;
	if (!grid || game->map.height <= 0)
		return (0);
	if (!count_player_positions(game, grid, &player_count))
		return (0);
	return (check_player_count(player_count));
}
