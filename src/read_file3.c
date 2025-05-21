/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:43:44 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/21 12:43:45 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	handle_line(char *line, char *clean, char **cfg, int *data[4])
{
	int				*map_count;
	char			**map_lines;
	t_config_data	config_data;

	map_count = data[2];
	map_lines = (char **)data[3];
	if (!is_config_line(clean))
	{
		if (is_valid_map_line(clean))
		{
			map_lines[*map_count] = ft_strdup(clean);
			(*map_count)++;
			return (2);
		}
		return (1);
	}
	config_data.clean_line = clean;
	config_data.line = line;
	config_data.fd = *(data[0]);
	config_data.cfg = cfg;
	config_data.count = data[1];
	if (!save_config_line(&config_data))
		return (-1);
	return (0);
}

int	process_file_line(t_parse_data *data, char *line, char *clean)
{
	int	*data_ptrs[4];
	int	result;

	data_ptrs[0] = &data->fd;
	data_ptrs[1] = &data->config_count;
	data_ptrs[2] = &data->map_count;
	data_ptrs[3] = (int *)data->map_lines;
	if (!data->in_map)
	{
		result = handle_line(line, clean, data->config_lines, data_ptrs);
		if (result == 2)
			data->in_map = 1;
		return (result != -1);
	}
	else
	{
		data->map_lines[data->map_count++] = ft_strdup(clean);
		return (1);
	}
}

int	process_line_and_clean(char *line, t_parse_data *data)
{
	char	*clean;
	int		result;

	clean = ft_strtrim(line, "\n");
	if (!clean)
	{
		free(line);
		return (0);
	}
	result = process_file_line(data, line, clean);
	if (!result)
	{
		free(clean);
		free(line);
		return (0);
	}
	free(clean);
	free(line);
	return (1);
}

int	process_file_lines(int fd, t_game *game, char *map_lines[1000],
		char *config_lines[10])
{
	t_parse_data	data;
	char			*line;

	(void)game;
	init_parse_data(&data, fd, map_lines, config_lines);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_line_and_clean(line, &data))
			return (0);
		line = get_next_line(fd);
	}
	return (data.map_count);
}

int	parse_file_content(int fd, t_game *game, char *map_lines[1000])
{
	int		map_count;
	char	*config_lines[10];

	map_count = process_file_lines(fd, game, map_lines, config_lines);
	if (map_count <= 0)
		return (map_count);
	if (!save_params(game, config_lines))
	{
		free_config_lines(config_lines, 10);
		return (-1);
	}
	free_config_lines(config_lines, 10);
	return (map_count);
}
