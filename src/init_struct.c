/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:30:51 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/16 12:50:23 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

void init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	init_pos(&map->player_pos);
	map->player_dir = 'N';
	map->valid = 0;
}

void init_player(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
}

void init_game(t_game *game)
{
	init_map(&game->map);
	init_player(&game->player);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_r = -1;
	game->floor_g = -1;
	game->floor_b = -1;
	game->ceiling_r = -1;
	game->ceiling_g = -1;
	game->ceiling_b = -1;
}

void init_texture(t_texture *texture)
{
	texture->img_ptr = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->bits_per_pixel = 0;
	texture->line_length = 0;
	texture->endian = 0;
}

void init_ray(t_ray *ray)
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

void init_mlx_game(t_mlx_game *mlx_game)
{
	init_map(&mlx_game->map);
	mlx_game->game = NULL;
	mlx_game->mlx = NULL;
	mlx_game->win = NULL;
	mlx_game->img.img_ptr = NULL;
	init_texture(&mlx_game->no_tex);
	init_texture(&mlx_game->so_tex);
	init_texture(&mlx_game->we_tex);
	init_texture(&mlx_game->ea_tex);
	init_ray(&mlx_game->ray);
}

void init_structs(t_mlx_game *mlx_game, t_game **game)
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
