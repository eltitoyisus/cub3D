/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:55:06 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/11 13:00:00 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	read_file(char *filepath)
{
	int		fd;
	char	*line;
	char	*clean_line;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		clean_line = ft_strtrim(line, "\n");
		printf("Leyendo línea: %s\n", clean_line);

		// Comprobación de línea RGB
		if (clean_line[0] == 'F' || clean_line[0] == 'C')
		{
			if (!valid_rgb(clean_line))
			{
				printf("❌ Línea RGB inválida: %s\n", clean_line);
				free(clean_line);
				free(line);
				close(fd);
				return (1);
			}
			else
				printf("✅ Línea RGB válida: %s\n", clean_line);
		}
		if (!ft_strncmp(clean_line, "NO ", 3) || !ft_strncmp(clean_line, "SO ", 3)
			|| !ft_strncmp(clean_line, "WE ", 3) || !ft_strncmp(clean_line, "EA ", 3))
		{
			if (!valid_sprite(clean_line))
			{
				printf("❌ Línea de sprite inválida: %s\n", clean_line);
				// Manejo de error
			}
			else
				printf("✅ Línea de sprite válida: %s\n", clean_line);
		}
		
		free(clean_line);
		free(line);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Error: invalid arg number\n"), 1);
	if (read_file(argv[1]) != 0)
		return (printf("❌ Mapa inválido\n"), 1);
	printf("✅ Mapa cargado correctamente\n");
	return (0);
}
