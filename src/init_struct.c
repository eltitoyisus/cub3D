/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:30:51 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/21 09:45:24 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

void	init_minimap(t_minimap *minimap)
{
	minimap->square_size = 20;
	minimap->width = 0;
	minimap->height = 0;
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	init_pos(&map->player_pos);
	map->player_dir = 'N';
	map->valid = 0;
}

void	init_player(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
}

void	init_game(t_game *game)
{
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
	init_map(&game->map);
	init_player(&game->player);
}
