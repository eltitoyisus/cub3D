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

int valid_folder(char *path)
{
	if (ft_strncmp(path, "./sprites/", 10) == 0)
		return 1;
	return (printf("Error: Invalid folder for path: %s\n", path), 0);
}

// MAKE THIS FOR LATER SO CAN PREVENT UNWANTED FILES

// int valid_xpm(char *path)
// {
// 	if (ft_strcmp(path, ".xpm") == 0)
// 		return 1;
// 	return 0;
// }

// int valid_route(char *route)
// {
// 	(void)route;
// }

int valid_sprite(char *line)
{
	char **parts;
	int valid;
	int i = 0;

	line = skip_white_spaces(line);
	parts = ft_split(line, ' ');
	if (!parts)
		return 0;
	valid = 0;
	while (parts[i])
		i++;
	if (i == 2 && valid_coordinate(parts[0]) && valid_folder(parts[1]))
		valid = 1;
	free_arr(parts);
	return valid;
}
