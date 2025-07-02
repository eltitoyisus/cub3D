/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:20:23 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/10 16:20:23 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	valid_value(char *str)
{
	int	value;
	int	i;

	while (*str == ' ')
		str++;
	if (!*str)
		return (0);
	if (*str == '0' && *(str + 1) == '\0')
		return (1);
	if (*str == '0')
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 3)
		return (0);
	value = ft_atoi(str);
	if (value < 0 || value > 255)
		return (0);
	return (1);
}

int	valid_rgb(char *line)
{
	char	**values;
	int		i;
	int		valid;

	if (!(line[0] == 'F' || line[0] == 'C'))
		return (0);
	values = ft_split(line + 2, ',');
	if (!values)
		return (0);
	i = 0;
	while (values[i])
		i++;
	valid = (i == 3);
	i = 0;
	while (values[i] && valid)
	{
		if (!valid_value(values[i]))
		{
			valid = 0;
			printf("Invalid RGB value: %s\n", values[i]);
		}
		i++;
	}
	free_arr(values);
	return (valid);
}

int	valid_format(char *input)
{
	char	**lines;
	int		i;
	int		valid_floor;
	int		valid_ceiling;

	lines = ft_split(input, '\n');
	if (!lines)
		return (0);
	i = 0;
	valid_floor = 0;
	valid_ceiling = 0;
	while (lines[i])
	{
		if (lines[i][0] == 'F' && valid_rgb(lines[i]))
			valid_floor = 1;
		else if (lines[i][0] == 'C' && valid_rgb(lines[i]))
			valid_ceiling = 1;
		i++;
	}
	free_arr(lines);
	return (valid_floor && valid_ceiling);
}
