/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:39:07 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 16:30:18 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	get_texture_coords(t_mlx_game *game, t_texture *texture, int y,
		int *coords)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		original_draw_start;

	wall_x = calculate_wall_x(game);
	coords[0] = (int)(wall_x * (double)texture->width);
	step = 1.0 * texture->height / game->ray.line_height;
	original_draw_start = -game->ray.line_height / 2 + HEIGHT / 2;
	if (original_draw_start < 0)
		tex_pos = -original_draw_start * step + (y - game->ray.draw_start)
			* step;
	else
		tex_pos = (y - game->ray.draw_start) * step;
	coords[1] = (int)tex_pos & (texture->height - 1);
}

int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
