/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:45:11 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/19 09:25:31 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int process_config_line(char *clean_line, int fd, char *line)
{
	if (clean_line[0] == 'F' || clean_line[0] == 'C')
	{
		if (!valid_rgb(clean_line))
		{
			free(clean_line);
			free(line);
			close(fd);
			return (0);
		}
	}
	else if (!ft_strncmp(clean_line, "NO ", 3)
		|| !ft_strncmp(clean_line, "SO ", 3)
		|| !ft_strncmp(clean_line, "WE ", 3)
		|| !ft_strncmp(clean_line, "EA ", 3))
	{
		if (!valid_sprite(clean_line))
		{
			free(clean_line);
			free(line);
			close(fd);
			return (0);
		}
	}
	return (1);
}

int parse_file_content(int fd, t_game *game, char *map_lines[1000])
{
	char *line;
	char *clean_line;
	int map_count;
	int in_map_section;
	int config_lines_count = 0;
	char *config_lines[10] = {NULL};
	int i;

	map_count = 0;
	in_map_section = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line)
			return 0;
		clean_line = ft_strtrim(line, "\n");
		if (!clean_line)
			return 0;
		if (!in_map_section && (clean_line[0] == 'N' || clean_line[0] == 'S' || 
			clean_line[0] == 'E' || clean_line[0] == 'W' || 
			clean_line[0] == 'F' || clean_line[0] == 'C'))
		{
			if (!process_config_line(clean_line, fd, line))
				return (-1);
			config_lines[config_lines_count++] = ft_strdup(clean_line);
		}
		else if (is_valid_map_line(clean_line))
		{
			in_map_section = 1;
			map_lines[map_count++] = ft_strdup(clean_line);
		}
		free(clean_line); free(line);
	}
	if (!save_params(game, config_lines))
	{
		i = 0;
		while (i < config_lines_count)
		{
			free(config_lines[i]);
			i++;
		}
		return (-1);
	}
	i = 0;
	while (i < config_lines_count)
	{
		free(config_lines[i]);
		i++;
	}
	return (map_count);
}

int build_game_map(t_game *game, char **map_lines, int map_count)
{
	int i;
	int max_width;

	i = 0;
	max_width = 0;
	while (i < map_count)
	{
		int len = ft_strlen(map_lines[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	game->map.height = map_count;
	game->map.width = max_width;
	game->map.grid = malloc(sizeof(char *) * (map_count + 1));
	if (!game->map.grid)
		return (0);
	i = 0;
	while (i < map_count)
	{
		game->map.grid[i] = map_lines[i];
		i++;
	}
	game->map.grid[map_count] = NULL;
	return (1);
}

int validate_game_map(t_game *game)
{
	if (!find_player_position(game))
		return (0);
	if (!valid_map(game))
		return (0);
	return (1);
}

int is_valid_map_line(char *line)
{
	int i = 0;

	if (!line || line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (!valid_char(line[i]) && !skip_white_spaces(line))
			return (0);
		i++;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || valid_player(line[i]))
			return (1);
		i++;
	}
	return (0);
}

t_game *read_file(char *filepath)
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
		return (free(game), NULL);
	map_count = parse_file_content(fd, game, map_lines);
	close(fd);
	if (map_count <= 0)
		return (free(game), NULL);
	if (!build_game_map(game, map_lines, map_count))
		return (free(game), NULL);
	if (!validate_game_map(game))
		return (free(game), NULL);
	return (game);
}
