/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:56:22 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/04 13:09:06 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init_parse_data(t_parse_data *data, int fd, char *map_lines[1000],
		char *config_lines[10])
{
	data->map_lines = map_lines;
	data->config_lines = config_lines;
	data->map_count = 0;
	data->config_count = 0;
	data->in_map = 0;
	data->fd = fd;
	ft_bzero(config_lines, sizeof(char *) * 10);
}

void	init_texture(t_texture *texture)
{
	if (!texture)
		return ;
	texture->img_ptr = NULL;
	texture->addr = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->bits_per_pixel = 0;
	texture->line_length = 0;
	texture->endian = 0;
}

void	init_ray(t_ray *ray)
{
	ray->pos_x = 0;
	ray->pos_y = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_mlx_game(t_mlx_game *mlx_game)
{
	init_map(&mlx_game->map);
	mlx_game->game = NULL;
	mlx_game->mlx = NULL;
	mlx_game->win = NULL;
	mlx_game->img.img_ptr = NULL;
	mlx_game->door_toggle = false;
	mlx_game->door_pos_x = -1;
	mlx_game->door_pos_y = -1;
	init_texture(&mlx_game->no_tex);
	init_texture(&mlx_game->so_tex);
	init_texture(&mlx_game->we_tex);
	init_texture(&mlx_game->ea_tex);
	init_texture(&mlx_game->door_open);
	init_texture(&mlx_game->door_close);
	init_ray(&mlx_game->ray);
	init_minimap(&mlx_game->minimap);
}

void	init_structs(t_mlx_game *mlx_game, t_game **game)
{
	init_mlx_game(mlx_game);
	*game = malloc(sizeof(t_game));
	if (*game)
		init_game(*game);
	mlx_game->game = *game;
	mlx_game->map = (*game)->map;
	mlx_game->img.img_ptr = NULL;
	mlx_game->img.addr = NULL;
	mlx_game->img.bits_per_pixel = 0;
	mlx_game->img.line_length = 0;
	mlx_game->img.endian = 0;
}
