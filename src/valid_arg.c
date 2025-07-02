/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:55:04 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 08:55:04 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	valid_ext(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ext && !ft_strncmp(ext, ".cub", 5))
		return (1);
	printf("Error: Invalid file extension. Only .cub files are supported.\n");
	return (0);
}

int	valid_route(char *filename)
{
	if (!ft_strncmp(filename, "maps/", 5))
		return (1);
	printf("Error: Map files must be in the 'maps/' directory.\n");
	return (0);
}

int	valid_arg(char *filename)
{
	return (valid_ext(filename) && valid_route(filename));
}
