/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:38:20 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/04 13:17:46 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	load_xpm(t_mlx_game *game, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img_ptr)
		return ;
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
}

void	init_textures(t_mlx_game *game)
{
	load_xpm(game, &game->no_tex, game->game->no_texture);
	load_xpm(game, &game->so_tex, game->game->so_texture);
	load_xpm(game, &game->we_tex, game->game->we_texture);
	load_xpm(game, &game->ea_tex, game->game->ea_texture);
	load_door(game);
}

void	load_door(t_mlx_game *game)
{
	load_xpm(game, &game->door_close, "./sprites/door_close.xpm");
}

int	valid_extension(char *path)
{
	char	*ext;

	if (!path)
		return (printf("Error: Path is NULL\n"), 0);
	ext = ft_strrchr(path, '.');
	if (ext && !ft_strcmp(ext, ".xpm"))
		return (1);
	return (printf("Error: Invalid file extension for '%s'. Expected .xpm\n",
			path), 0);
}
