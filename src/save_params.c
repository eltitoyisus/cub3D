/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:32:00 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/16 11:06:55 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int save_floor(t_game *game, char *line)
{
	char **values;

	values = ft_split(line + 2, ',');
	if (!values)
		return (0);
	game->floor_r = ft_atoi(values[0]);
	game->floor_g = ft_atoi(values[1]);
	game->floor_b = ft_atoi(values[2]);
	free_arr(values);
	return (1);
}

int save_ceiling(t_game *game, char *line)
{
	char **values;

	values = ft_split(line + 2, ',');
	if (!values)
		return (0);
	game->ceiling_r = ft_atoi(values[0]);
	game->ceiling_g = ft_atoi(values[1]);
	game->ceiling_b = ft_atoi(values[2]);
	free_arr(values);
	return (1);
}

int save_rgb(t_game *game, char **lines)
{
	int i;

	i = 0;
	while (lines[i])
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
		i++;
	}
	return (1);
}

int save_textures(t_game *game, char **lines)
{
	int i;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] == 'N' && lines[i][1] == 'O')
			game->no_texture = ft_strdup(lines[i] + 3);
		else if (lines[i][0] == 'S' && lines[i][1] == 'O')
			game->so_texture = ft_strdup(lines[i] + 3);
		else if (lines[i][0] == 'W' && lines[i][1] == 'E')
			game->we_texture = ft_strdup(lines[i] + 3);
		else if (lines[i][0] == 'E' && lines[i][1] == 'A')
			game->ea_texture = ft_strdup(lines[i] + 3);
		i++;
	}
	return (1);
}

int save_params(t_game *game, char **lines)
{
	if (!save_rgb(game, lines))
		return (0);
	if (!save_textures(game, lines))
		return (0);
	return (1);
}

