/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:27:02 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/15 20:11:55 by jramos-a         ###   ########.fr       */
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

typedef struct s_player
{
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
} t_player;

typedef struct s_game
{
	t_map map;
	t_player player;
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

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_texture;

typedef struct s_mlx_game
{
	t_map		map;
	t_game		*game;
	void		*mlx;
	void		*win;
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_texture	ea_tex;
} t_mlx_game;

#endif
