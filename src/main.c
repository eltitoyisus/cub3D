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
	t_mlx_game	mlx_game;
	t_game		*game;
	t_game		*game_ptr;
	t_game		*temp;

	if (argc != 2)
		return (printf("Error: invalid arg number\n"), 1);
	if (!valid_arg(argv[1]))
		return (1);
	init_structs(&mlx_game, &game);
	temp = read_file(argv[1]);
	free_game(game);
	game_ptr = temp;
	if (game_ptr == NULL)
		return (1);
	if (!find_player_position(game_ptr) || !save_player_direction(game_ptr))
		return (1);
	mlx_game.game = game_ptr;
	printf("✅ Mapa cargado correctamente\n");
	mlx_game.map = game_ptr->map;
	if (ft_init(&mlx_game) != 0)
		return (1);
	return (0);
}
