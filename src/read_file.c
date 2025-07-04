/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:43:42 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/04 11:58:14 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->no_texture)
		free(game->no_texture);
	if (game->so_texture)
		free(game->so_texture);
	if (game->we_texture)
		free(game->we_texture);
	if (game->ea_texture)
		free(game->ea_texture);
	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height && game->map.grid[i])
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	free(game);
}

int	init_game_map(t_game *game, char **map_lines, int map_count, int *max_width)
{
	int	i;
	int	len;

	i = 0;
	*max_width = 0;
	while (i < map_count)
	{
		len = ft_strlen(map_lines[i]);
		if (len > *max_width)
			*max_width = len;
		i++;
	}
	if (*max_width > 300 || map_count > 300)
		return (printf("Error: Map dimensions cannot exceed 300\n"), 0);
	game->map.height = map_count;
	game->map.width = *max_width;
	game->map.grid = malloc(sizeof(char *) * (map_count + 1));
	if (!game->map.grid)
		return (0);
	return (1);
}

int	fill_game_map(t_game *game, char **map_lines, int map_count, int max_width)
{
	int		i;
	int		len;
	char	*padded_line;

	i = 0;
	while (i < map_count)
	{
		padded_line = malloc(max_width + 1);
		if (!padded_line)
		{
			while (--i >= 0)
				free(game->map.grid[i]);
			return (free(game->map.grid), 0);
		}
		ft_strcpy(padded_line, map_lines[i]);
		len = ft_strlen(padded_line);
		while (len < max_width)
			padded_line[len++] = ' ';
		padded_line[max_width] = '\0';
		game->map.grid[i] = padded_line;
		free(map_lines[i]);
		i++;
	}
	game->map.grid[map_count] = NULL;
	return (1);
}

int	build_game_map(t_game *game, char **map_lines, int map_count)
{
	int	max_width;

	if (!init_game_map(game, map_lines, map_count, &max_width))
	{
		free_map_lines(map_lines, map_count);
		return (0);
	}
	if (!fill_game_map(game, map_lines, map_count, max_width))
		return (0);
	return (1);
}

t_game	*read_file(char *filepath)
{
	int		fd;
	t_game	*game;
	char	*map_lines[1000];
	int		map_count;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (free_game(game), NULL);
	map_count = parse_file_content(fd, game, map_lines);
	close(fd);
	if (map_count <= 0)
		return (free_game(game), NULL);
	if (!build_game_map(game, map_lines, map_count))
		return (free_game(game), NULL);
	if (!validate_game_map(game))
		return (free_game(game), NULL);
	return (game);
}
