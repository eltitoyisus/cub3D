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

void	map_cpy(char **src, char ***dest, int width, int height)
{
	int	i;

	i = 0;
	*dest = malloc(sizeof(char *) * (height + 1));
	if (!*dest)
		return ;
	while (i < height)
	{
		(*dest)[i] = malloc(sizeof(char) * (width + 1));
		if (!(*dest)[i])
		{
			while (i-- > 0)
				free((*dest)[i - 1]);
			free(*dest);
			*dest = NULL;
			return ;
		}
		if (src && src[i])
			ft_strcpy((*dest)[i], src[i]);
		else
			(*dest)[i][0] = '\0';
		i++;
	}
	(*dest)[height] = NULL;
}

int	is_valid_map_structure(t_game *game)
{
	if (!game->map.grid || game->map.width <= 0 || game->map.height <= 0)
	{
		game->map.valid = 0;
		return (0);
	}
	if (!find_player_position(game) || !valid_map_chars(game->map.grid,
			game->map.width, game->map.height))
	{
		game->map.valid = 0;
		return (0);
	}
	return (1);
}

char	**create_temp_grid(t_game *game, int height)
{
	char	**temp_grid;
	int		i;

	temp_grid = malloc(sizeof(char *) * (height + 1));
	if (!temp_grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		temp_grid[i] = ft_strdup(game->map.grid[i]);
		if (!temp_grid[i])
		{
			while (i-- >= 0)
				free(temp_grid[i]);
			free(temp_grid);
			return (NULL);
		}
		i++;
	}
	temp_grid[height] = NULL;
	return (temp_grid);
}

int	valid_map(t_game *game)
{
	int	map_breached;

	map_breached = 0;
	if (!is_valid_map_structure(game))
		return (0);
	if (!check_map_boundary(game))
	{
		printf("Error: Map not properly enclosed by walls\n");
		game->map.valid = 0;
		return (0);
	}
	if (!perform_flood_fill(game, &map_breached))
		return (0);
	if (map_breached)
	{
		printf("Invalid map type\n");
		game->map.valid = 0;
		return (0);
	}
	game->map.valid = 1;
	return (1);
}
