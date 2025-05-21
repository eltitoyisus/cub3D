/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:12:13 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 10:08:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_substr(buffer, 0, i + ft_putend(buffer));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_freebuff(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*ft_readndfree(char *str, char *buf)
{
	char	*temp;

	temp = NULL;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	if (!buf)
		return (str);
	temp = ft_strjoin(str, buf);
	free(str);
	return (temp);
}

char	*read_buffer(int fd, char *buffer, char *temp)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && (!buffer || !ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = ft_readndfree(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buffer = read_buffer(fd, buffer, temp);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_freebuff(buffer);
	return (line);
}
