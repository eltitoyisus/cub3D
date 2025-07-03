/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:20:32 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/10 12:00:00 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	is_valid_char_for_boundary(char c)
{
	return (c == '1' || c == ' ' || c == 'D');
}

void	flood_fill(t_game *game, t_flood_context *ctx, int x, int y)
{
	if (x < 0 || x >= ctx->width || y < 0 || y >= ctx->height)
	{
		*(ctx->breached) = 1;
		return ;
	}
	if (ctx->grid[y][x] == '1' || ctx->grid[y][x] == 'V')
		return ;
	ctx->grid[y][x] = 'V';
	flood_fill(game, ctx, x + 1, y);
	flood_fill(game, ctx, x - 1, y);
	flood_fill(game, ctx, x, y + 1);
	flood_fill(game, ctx, x, y - 1);
}

void	inverse_flood_fill(t_flood_context *ctx, int x, int y, int *has_breach)
{
	if (x < 0 || x >= ctx->width || y < 0 || y >= ctx->height || *has_breach
		|| ctx->grid[y][x] == 'F')
		return ;
	if (ctx->grid[y][x] == '0' || ctx->grid[y][x] == 'N'
		|| ctx->grid[y][x] == 'S' || ctx->grid[y][x] == 'E'
		|| ctx->grid[y][x] == 'W')
	{
		*has_breach = 1;
		return ;
	}
	if (ctx->grid[y][x] == ' ')
		ctx->grid[y][x] = 'F';
	else
		return ;
	inverse_flood_fill(ctx, x + 1, y, has_breach);
	inverse_flood_fill(ctx, x - 1, y, has_breach);
	inverse_flood_fill(ctx, x, y + 1, has_breach);
	inverse_flood_fill(ctx, x, y - 1, has_breach);
}

int	perform_flood_fill(t_game *game, int *map_breached)
{
	char			**temp_grid;
	t_flood_context	ctx;

	temp_grid = create_temp_grid(game, game->map.height);
	if (!temp_grid)
		return (0);
	ctx.grid = temp_grid;
	ctx.width = game->map.width;
	ctx.height = game->map.height;
	ctx.breached = map_breached;
	flood_fill(game, &ctx, game->map.player_pos.x, game->map.player_pos.y);
	free_temp_grid(temp_grid, game->map.height);
	return (1);
}
