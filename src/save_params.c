/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:43:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/21 12:43:58 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	save_floor(t_game *game, char *line)
{
	char	**values;

	values = ft_split(line + 2, ',');
	if (!values)
		return (0);
	game->floor_r = ft_atoi(values[0]);
	game->floor_g = ft_atoi(values[1]);
	game->floor_b = ft_atoi(values[2]);
	free_arr(values);
	return (1);
}

int	save_ceiling(t_game *game, char *line)
{
	char	**values;

	values = ft_split(line + 2, ',');
	if (!values)
		return (0);
	game->ceiling_r = ft_atoi(values[0]);
	game->ceiling_g = ft_atoi(values[1]);
	game->ceiling_b = ft_atoi(values[2]);
	free_arr(values);
	return (1);
}

int	save_rgb(t_game *game, char **lines)
{
	int	i;

	if (!game || !lines)
		return (0);
	i = 0;
	while (lines && lines[i])
	{
		if (lines[i] && *lines[i])
		{
			if (lines[i][0] == 'F')
			{
				if (!save_floor(game, lines[i]))
					return (0);
			}
			else if (lines[i][0] == 'C')
			{
				if (!save_ceiling(game, lines[i]))
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	save_texture(t_game *game, char *line, char **texture_ptr)
{
	(void)game;
	if (ft_strlen(line) >= 3)
		*texture_ptr = ft_strdup(line + 3);
	return (1);
}

int	save_textures(t_game *game, char **lines)
{
	int	i;

	if (!game || !lines)
		return (0);
	i = 0;
	while (lines && lines[i])
	{
		if (lines[i] && ft_strlen(lines[i]) >= 2)
		{
			if (lines[i][0] == 'N' && lines[i][1] == 'O')
				save_texture(game, lines[i], &game->no_texture);
			else if (lines[i][0] == 'S' && lines[i][1] == 'O')
				save_texture(game, lines[i], &game->so_texture);
			else if (lines[i][0] == 'W' && lines[i][1] == 'E')
				save_texture(game, lines[i], &game->we_texture);
			else if (lines[i][0] == 'E' && lines[i][1] == 'A')
				save_texture(game, lines[i], &game->ea_texture);
		}
		i++;
	}
	return (1);
}
