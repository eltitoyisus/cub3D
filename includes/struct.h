/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:55:11 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 08:55:11 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "headers.h"

typedef struct s_pos
{
	int x;
	int y;
} t_pos;

typedef struct s_map
{
	char **grid;
	int width;
	int height;
	t_pos player_pos;
	char player_dir;
	int valid;
} t_map;

typedef struct s_game
{
	t_map map;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	int floor_r;
	int floor_g;
	int floor_b;
	int ceiling_r;
	int ceiling_g;
	int ceiling_b;
} t_game;

#endif
