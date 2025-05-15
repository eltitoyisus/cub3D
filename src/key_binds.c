/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:44:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/15 10:44:36 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int handle_exit(t_mlx_game *game)
{
	return(ft_destroy(game->mlx), 1);
}

// int ft_look(t_mlx_game *game)
// {

// }

// int ft_movement(t_mlx_game *game)
// {

// }

// int key_handle(int keycode, void *param)
// {
// 	(void)param;
// 	if (keycode == LOOK_RIGHT || keycode == LOOK_LEFT)
// 		ft_look();
// 	else if(keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
// 		ft_movement();
// 	else if (keycode == KEY_ESC)
// 		handle_exit();
// 	return (0);
// }
