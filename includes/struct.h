/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:27:02 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/04 13:17:19 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "headers.h"

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_minimap
{
	int			square_size;
	int			width;
	int			height;
}				t_minimap;

typedef struct s_parse_data
{
	char		**map_lines;
	char		**config_lines;
	int			map_count;
	int			config_count;
	int			in_map;
	int			fd;
}				t_parse_data;

typedef struct s_draw_data
{
	int			start;
	int			end;
	int			color;
}				t_draw_data;

typedef struct s_config_data
{
	char		*clean_line;
	char		*line;
	int			fd;
	char		**cfg;
	int			*count;
}				t_config_data;

typedef struct s_flood_context
{
	char		**grid;
	int			width;
	int			height;
	int			*breached;
}				t_flood_context;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_pos		player_pos;
	char		player_dir;
	int			valid;
}				t_map;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*door_open;
	char		*door_close;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
}				t_game;

typedef struct s_texture
{
	void		*img_ptr;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_input
{
	int			move_forward;
	int			move_backward;
	int			move_left;
	int			move_right;
	int			turn_left;
	int			turn_right;
}				t_input;

typedef struct s_texture_args
{
	int			*has_tex;
	char		*id;
	char		**tex_ptr;
}				t_texture_args;

typedef struct s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_mlx_game
{
	t_map		map;
	t_game		*game;
	void		*mlx;
	void		*win;
	t_texture	img;
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_texture	ea_tex;
	t_texture	door_open;
	t_texture	door_close;
	int			door_toggle;
	int			door_pos_x;
	int			door_pos_y;
	t_ray		ray;
	t_minimap	minimap;
	t_input		input;
}				t_mlx_game;

#endif
