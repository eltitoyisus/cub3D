/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:10:45 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/22 12:12:30 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
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

int	is_config_line(char *line)
{
	if (!line)
		return (0);
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W'
		|| line[0] == 'F' || line[0] == 'C')
		return (1);
	return (0);
}

int	is_valid_map_line(char *line)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!line || line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (!valid_char(line[i]) && !skip_white_spaces(line))
			return (0);
		if (line[i] == '0' || line[i] == '1' || valid_player(line[i]))
			found = 1;
		i++;
	}
	return (found);
}

void	free_config_lines(char **config_lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (config_lines[i] != NULL)
			free(config_lines[i]);
		i++;
	}
}

int	save_config_line(t_config_data *data)
{
	char	*duplicated_line;

	if (!data->clean_line || !data->fd || !data->line)
		return (0);
	if (!process_config_line(data->clean_line, data->fd, data->line))
		return (0);
	duplicated_line = ft_strdup(data->clean_line);
	if (!duplicated_line)
		return (0);
	if (*(data->count) >= 10)
	{
		free(duplicated_line);
		return (0);
	}
	data->cfg[*(data->count)] = duplicated_line;
	(*(data->count))++;
	return (1);
}
