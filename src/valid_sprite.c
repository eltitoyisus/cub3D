/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:21:10 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 09:21:10 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	valid_coordinate(char *coordinate)
{
	if (!coordinate)
		return (0);
	if (!ft_strcmp(coordinate, "NO") || !ft_strcmp(coordinate, "SO")
		|| !ft_strcmp(coordinate, "WE") || !ft_strcmp(coordinate, "EA"))
		return (1);
	return (printf("Error: Invalid coordinate %s\n", coordinate), 0);
}

int	valid_folder(char *path)
{
	if (ft_strncmp(path, "./sprites/", 10) == 0 || ft_strncmp(path, "sprites/",
			8) == 0)
		return (1);
	else
		return (printf("Error: Invalid folder for path: %s\n", path), 0);
}

char	*extract_path(char *line, int start_idx)
{
	char	*path;
	char	*trimmed_path;
	char	*result;

	path = ft_substr(line, start_idx + 1, ft_strlen(line) - start_idx - 1);
	if (!path)
		return (NULL);
	trimmed_path = path;
	while (*trimmed_path && (*trimmed_path == ' ' || *trimmed_path == '\t'))
		trimmed_path++;
	result = ft_strdup(trimmed_path);
	free(path);
	return (result);
}

int	check_multiple_definitions(char *path)
{
	int	i;

	i = 0;
	while (path[i] && path[i] != ' ')
		i++;
	if (path[i] != '\0')
		return (0);
	return (1);
}

int	valid_sprite(char *line)
{
	char	*trimmed_line;
	char	*identifier;
	char	*path;
	int		i;
	int		valid;

	trimmed_line = skip_white_spaces(line);
	if (!trimmed_line)
		return (0);
	i = 0;
	while (trimmed_line[i] && trimmed_line[i] != ' ')
		i++;
	if (trimmed_line[i] != ' ' || i == 0)
		return (free(trimmed_line), printf("Error: Invalid sprite\n"), 0);
	identifier = ft_substr(trimmed_line, 0, i);
	path = extract_path(trimmed_line, i);
	valid = valid_coordinate(identifier);
	if (valid && !valid_folder(path))
		valid = 0;
	else if (valid && !check_multiple_definitions(path))
		return (free(identifier), free(path), free(trimmed_line),
			printf("Error: Multiple definitions in one line\n"), 0);
	if (valid)
		valid = valid_extension(path);
	return (free(identifier), free(path), free(trimmed_line), valid);
}
