/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:33:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/22 12:33:36 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	validate_game_map(t_game *game)
{
	if (!find_player_position(game))
		return (0);
	if (!valid_map(game))
		return (0);
	return (1);
}

int	process_config_line(char *clean_line, int fd, char *line)
{
	(void)fd;
	(void)line;
	if (ft_count_words(clean_line, ' ') != 2)
		return (0);
	if (clean_line[0] == 'F' || clean_line[0] == 'C')
	{
		if (!valid_rgb(clean_line))
			return (0);
	}
	else if (!ft_strncmp(clean_line, "NO ", 3) || !ft_strncmp(clean_line, "SO ",
			3) || !ft_strncmp(clean_line, "WE ", 3) || !ft_strncmp(clean_line,
			"EA ", 3))
	{
		if (!valid_sprite(clean_line))
			return (0);
	}
	else
		return (0);
	return (1);
}
