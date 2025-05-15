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

int	main(int argc, char **argv)
{
	t_mlx_game	game;

	if (argc != 2)
		return (printf("Error: invalid arg number\n"), 1);
	if (read_file(argv[1]) != 0)
		return (printf("❌ Mapa inválido\n"), 1);
	else
	{
		printf("✅ Mapa cargado correctamente\n");
		ft_init(&game);
	}
	return (0);
}
