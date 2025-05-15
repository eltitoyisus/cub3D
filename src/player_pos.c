/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:23:09 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 09:23:09 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void player_facing_north(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0;
}

void player_facing_south(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
}

void player_facing_east(t_game *game)
{
	game->player.dir_x = 1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
}

void player_facing_west(t_game *game)
{
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = -0.66;
}

int save_player_direction(t_game *game)
{
	if (!game)
		return (0);
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	if (game->map.player_dir == 'N')
		player_facing_north(game);
	else if (game->map.player_dir == 'S')
		player_facing_south(game);
	else if (game->map.player_dir == 'E')
		player_facing_east(game);
	else if (game->map.player_dir == 'W')
		player_facing_west(game);
	else
		return (0);
	game->player.pos_x = game->map.player_pos.x + 0.5;
	game->player.pos_y = game->map.player_pos.y + 0.5;
	return (1);
}
