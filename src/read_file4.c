/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:33:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/22 12:33:36 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	validate_game_map(t_game *game)
{
	if (!find_player_position(game))
		return (0);
	if (!valid_map(game))
		return (0);
	return (1);
}

void	free_map_lines_partial(char **map_lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (map_lines[i])
		{
			free(map_lines[i]);
			map_lines[i] = NULL;
		}
		i++;
	}
}

int	process_config_line(char *clean_line, int fd, char *line)
{
	char	*trimmed;

	(void)fd;
	(void)line;
	trimmed = clean_line;
	while (*trimmed && (*trimmed == ' ' || *trimmed == '\t'))
		trimmed++;
	if (trimmed[0] == 'F' || trimmed[0] == 'C')
	{
		if (ft_count_words(trimmed, ' ') != 2)
			return (printf("Error: Invalid RGB format\n"), 0);
		if (!valid_rgb(trimmed))
			return (0);
	}
	else if (!ft_strncmp(trimmed, "NO ", 3) || !ft_strncmp(trimmed, "SO ", 3)
		|| !ft_strncmp(trimmed, "WE ", 3) || !ft_strncmp(trimmed, "EA ", 3))
	{
		if (!valid_sprite(trimmed))
			return (0);
	}
	else
		return (printf("Error: Invalid configuration: %s\n", clean_line), 0);
	return (1);
}
