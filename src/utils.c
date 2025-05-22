/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:47:03 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/22 11:38:28 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*skip_white_spaces(char *line)
{
	char	*trimmed;
	char	*result;

	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, " \t\n\v\f\r");
	if (!trimmed)
		return (NULL);
	result = ft_strdup(trimmed);
	free(trimmed);
	return (result);
}

char	*clean_line_str(char *line)
{
	if (!line)
		return (NULL);
	return (ft_strtrim(line, "\n"));
}

void	free_temp_grid(char **temp_grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(temp_grid[i]);
		i++;
	}
	free(temp_grid);
}
