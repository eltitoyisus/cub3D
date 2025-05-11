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

static void	print_map(char **map, int height)
{
	int y = 0;
	while (y < height)
	{
		printf("%s\n", map[y]);
		y++;
	}
}


static void	free_split(char **split, int rows)
{
	int i = 0;
	while (i < rows)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

static int	set_player(t_map *map, int x, int y, char dir)
{
	if (map->player_pos.x != -1)
		return (0); // ya hay jugador
	map->player_pos.x = x;
	map->player_pos.y = y;
	map->player_dir = dir;
	return (1);
}

static char	**allocate_grid(int height, int width)
{
	char **grid = malloc(sizeof(char *) * height);
	if (!grid)
		return (NULL);
	int i = 0;
	while (i < height)
	{
		grid[i] = malloc(width + 1);
		if (!grid[i])
		{
			free_split(grid, i);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

static char	**create_visited(t_map *map)
{
	char **visited = malloc(sizeof(char *) * map->height);
	if (!visited)
		return (NULL);
	int y = 0;
	while (y < map->height)
	{
		visited[y] = malloc(map->width + 1);
		if (!visited[y])
		{
			free_split(visited, y);
			return (NULL);
		}
		int x = 0;
		while (x < map->width)
		{
			visited[y][x] = '0';
			x++;
		}
		visited[y][x] = '\0';
		y++;
	}
	return (visited);
}

static void	do_flood_fill(t_map *map, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return;
	if (visited[y][x] == '1' || map->grid[y][x] == '1' || map->grid[y][x] == ' ')
		return;

	visited[y][x] = '1';
	do_flood_fill(map, x + 1, y, visited);
	do_flood_fill(map, x - 1, y, visited);
	do_flood_fill(map, x, y + 1, visited);
	do_flood_fill(map, x, y - 1, visited);
}

static int	check_boundaries(t_map *map, char **visited)
{
	int y = 0;
	while (y < map->height)
	{
		int x = 0;
		while (x < map->width)
		{
			if (visited[y][x] == '1')
			{
				if (x == 0 || y == 0 || x == map->width - 1 || y == map->height - 1)
					return (0);
				if (map->grid[y][x] == ' ')
					return (0);
			}
			if ((map->grid[y][x] == '0' || map->grid[y][x] == 'N' || map->grid[y][x] == 'S' ||
				map->grid[y][x] == 'E' || map->grid[y][x] == 'W') && visited[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	parse_map(char *filename, t_map *map)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	
	map->player_pos.x = -1;
	map->player_pos.y = -1;
	map->valid = 0;

	char *line;
	int lines = 0, max_width = 0;
	while ((line = get_next_line(fd)))
	{
		int len = ft_strlen(line);
		if (len > max_width)
			max_width = len;
		lines++;
		free(line);
	}
	close(fd);

	map->width = max_width;
	map->height = lines;
	map->grid = allocate_grid(lines, max_width);
	if (!map->grid)
		return (0);

	fd = open(filename, O_RDONLY);
	int y = 0;
	while ((line = get_next_line(fd)))
	{
		int x = 0;
		while (line[x] && x < max_width)
		{
			char c = line[x];
			if (!is_valid_char(c))
				return (free(line), close(fd), 0);
			map->grid[y][x] = c;
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				if (!set_player(map, x, y, c))
					return (free(line), close(fd), 0);
			x++;
		}
		while (x < max_width)
			map->grid[y][x++] = ' ';
		map->grid[y][x] = '\0';
		free(line);
		y++;
	}
	close(fd);
	map->valid = (map->player_pos.x != -1);
	return (map->valid);
}

int	valid_map(char *filename)
{
	t_map map;
	if (!parse_map(filename, &map))
		return (0);

	char **visited = create_visited(&map);
	if (!visited)
		return (0);

	do_flood_fill(&map, map.player_pos.x, map.player_pos.y, visited);
	printf("Floodfill result:\n");
	print_map(visited, map.height);
	int result = check_boundaries(&map, visited);

	free_split(visited, map.height);
	free_split(map.grid, map.height);
	return (result);
}
