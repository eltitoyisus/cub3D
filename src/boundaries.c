/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:55:56 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 21:55:56 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	check_horizontal_boundaries(t_flood_context *ctx, int *has_breach)
{
	int	x;

	x = 0;
	while (x < ctx->width)
	{
		if (ctx->grid[0][x] == ' ')
			inverse_flood_fill(ctx, x, 0, has_breach);
		if (ctx->grid[ctx->height - 1][x] == ' ')
			inverse_flood_fill(ctx, x, ctx->height - 1, has_breach);
		x++;
	}
	return (1);
}

int	check_vertical_boundaries(t_flood_context *ctx, int *has_breach)
{
	int	y;

	y = 0;
	while (y < ctx->height)
	{
		if (ctx->grid[y][0] == ' ')
			inverse_flood_fill(ctx, 0, y, has_breach);
		if (ctx->grid[y][ctx->width - 1] == ' ')
			inverse_flood_fill(ctx, ctx->width - 1, y, has_breach);
		y++;
	}
	return (1);
}

int	is_boundary_valid(t_game *game, int i, int j)
{
	char	**grid;

	grid = game->map.grid;
	if (i == 0 || j == 0 || i == game->map.height - 1 || j == game->map.width
		- 1)
		return (0);
	if (j + 1 >= game->map.width || i + 1 >= game->map.height)
		return (0);
	if (grid[i - 1][j] == ' ' || grid[i + 1][j] == ' ')
		return (0);
	if (grid[i][j - 1] == ' ' || grid[i][j + 1] == ' ')
		return (0);
	if (grid[i - 1][j - 1] == ' ' || grid[i - 1][j + 1] == ' ')
		return (0);
	if (grid[i + 1][j - 1] == ' ' || grid[i + 1][j + 1] == ' ')
		return (0);
	return (1);
}

int	check_map_boundary(t_game *game)
{
	int		i;
	int		j;
	char	**grid;

	grid = game->map.grid;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if ((grid[i][j] == '0' || grid[i][j] == 'D'
					|| valid_player(grid[i][j])) && !is_boundary_valid(game, i,
					j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
