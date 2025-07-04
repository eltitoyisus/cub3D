/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:26:55 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/03 14:26:55 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	check_rgb_line(char *line, int *has_color, char type)
{
	if (line[0] == type)
	{
		if (*has_color)
			return (printf("Error: Duplicate %c color definition\n", type), 0);
		*has_color = 1;
		return (1);
	}
	return (0);
}

int	process_rgb_line(t_game *game, char *line, int *has_floor, int *has_ceiling)
{
	if (line && *line)
	{
		if (check_rgb_line(line, has_floor, 'F'))
		{
			if (!save_floor(game, line))
				return (0);
		}
		else if (check_rgb_line(line, has_ceiling, 'C'))
		{
			if (!save_ceiling(game, line))
				return (0);
		}
	}
	return (1);
}

int	save_rgb(t_game *game, char **lines)
{
	int	i;
	int	has_floor;
	int	has_ceiling;

	if (!game || !lines)
		return (0);
	i = 0;
	has_floor = 0;
	has_ceiling = 0;
	while (lines && lines[i])
	{
		if (!process_rgb_line(game, lines[i], &has_floor, &has_ceiling))
			return (0);
		i++;
	}
	if (!has_floor)
		printf("Error: Missing floor (F) color definition\n");
	if (!has_ceiling)
		printf("Error: Missing ceiling (C) color definition\n");
	return (has_floor && has_ceiling);
}

int	process_texture(t_game *game, char *line, t_texture_args *args)
{
	if (line[0] == args->id[0] && line[1] == args->id[1])
	{
		if (*(args->has_tex))
			return (printf("Error: Duplicate %s texture definition\n",
					args->id), 0);
		*(args->has_tex) = 1;
		return (save_texture(game, line, args->tex_ptr));
	}
	return (1);
}
