/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:43:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/04 17:22:02 by jramos-a         ###   ########.fr       */
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

int	save_texture(t_game *game, char *line, char **texture_ptr)
{
	(void)game;
	if (ft_strlen(line) >= 3)
		*texture_ptr = ft_strdup(line + 3);
	return (1);
}

int	check_texture_line(t_game *game, char *line, int *flags, char ***textures)
{
	t_texture_args	args;

	if (!line || ft_strlen(line) < 2)
		return (1);
	args.has_tex = &flags[0];
	args.id = "NO";
	args.tex_ptr = textures[0];
	if (!process_texture(game, line, &args))
		return (0);
	args.has_tex = &flags[1];
	args.id = "SO";
	args.tex_ptr = textures[1];
	if (!process_texture(game, line, &args))
		return (0);
	args.has_tex = &flags[2];
	args.id = "WE";
	args.tex_ptr = textures[2];
	if (!process_texture(game, line, &args))
		return (0);
	args.has_tex = &flags[3];
	args.id = "EA";
	args.tex_ptr = textures[3];
	if (!process_texture(game, line, &args))
		return (0);
	return (1);
}

int	save_textures(t_game *game, char **lines)
{
	int		i;
	int		flags[4];
	char	**textures[4];

	if (!game || !lines)
		return (0);
	i = 0;
	ft_bzero(flags, sizeof(flags));
	textures[0] = &game->no_texture;
	textures[1] = &game->so_texture;
	textures[2] = &game->we_texture;
	textures[3] = &game->ea_texture;
	while (lines && lines[i])
		if (!check_texture_line(game, lines[i++], flags, textures))
			return (0);
	if (!flags[0])
		printf("Error: Missing NO (north) texture\n");
	if (!flags[1])
		printf("Error: Missing SO (south) texture\n");
	if (!flags[2])
		printf("Error: Missing WE (west) texture\n");
	if (!flags[3])
		printf("Error: Missing EA (east) texture\n");
	return (flags[0] && flags[1] && flags[2] && flags[3]);
}
