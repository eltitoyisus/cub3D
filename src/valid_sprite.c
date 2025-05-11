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

int valid_coordinate(char *coordinate)
{
	if (!coordinate)
		return 0;
	if (!ft_strcmp(coordinate, "NO") || 
		!ft_strcmp(coordinate, "SO") || 
		!ft_strcmp(coordinate, "WE") || 
		!ft_strcmp(coordinate, "EA"))
		return 1;
	return 0;
}

int valid_folder(char *filename)
{
	if (!ft_strcmp(filename, "sprites/"))
		return 1;
	return 0;
}

int valid_file_exists(char *path)
{
	int fd;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return 0;
	close(fd);
	return 1;
}

int valid_sprite(char *line)
{
	char **parts;
	int valid;
	
	parts = ft_split(line, ' ');
	if (!parts)
		return 0;
	valid = 0;
	if (parts[0] && parts[1] && !parts[2])
	{
		if (valid_coordinate(parts[0]))
		{
			if (valid_folder(parts[1]) && valid_file_exists(parts[1]))
				valid = 1;
		}
	}
	free_arr(parts);
	return valid;
}

int check_all_directions(char *input)
{
	char **lines;
	int i;
	int no_found, so_found, we_found, ea_found;
	
	lines = ft_split(input, '\n');
	if (!lines)
		return 0;

	i = 0;
	no_found = 0;
	so_found = 0;
	we_found = 0;
	ea_found = 0;
	while (lines[i])
	{
		if (!ft_strcmp(lines[i], "NO ") && valid_sprite(lines[i]))
			no_found = 1;
		else if (!ft_strcmp(lines[i], "SO ") && valid_sprite(lines[i]))
			so_found = 1;
		else if (!ft_strcmp(lines[i], "WE ") && valid_sprite(lines[i]))
			we_found = 1;
		else if (!ft_strcmp(lines[i], "EA ") && valid_sprite(lines[i]))
			ea_found = 1;
		i++;
	}
	
	free_arr(lines);
	return (no_found && so_found && we_found && ea_found);
}