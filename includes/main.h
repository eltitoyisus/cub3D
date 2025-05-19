/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:55:08 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 08:55:08 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "headers.h"
# include "struct.h"

// PARSE
// INIT STRUCTS
void	init_pos(t_pos *pos);
void	init_map(t_map *map);
void	init_player(t_player *player);
void	init_game(t_game *game);
void	init_texture(t_texture *texture);
void	init_ray(t_ray *ray);
void	init_mlx_game(t_mlx_game *mlx_game);
void	init_structs(t_mlx_game *mlx_game, t_game **game);

// VALID INPUT
int		valid_ext(char *filename);
int		valid_route(char *filename);
int		valid_arg(char *filename);

// VALID SPRITES
int		valid_coordinate(char *coordinate);
int		valid_folder(char *filename);
int		valid_sprite(char *line);

// VALID RGB
int		valid_value(char *str);
int		valid_rgb(char *line);
int		valid_format(char *input);

// VALID MAP
int		valid_player(char c);
int		valid_char(char c);
int		valid_map_chars(char **grid, int width, int height);
void	set_player(t_game *game, int x, int y, char dir);
int		find_player_position(t_game *game);
void	map_cpy(char **src, char ***dest, int width, int height);
void	flood_fill(t_game *game, char **grid, int x, int y,
			int width, int height, int *map_breached);
int		valid_map(t_game *game);

// READ FILE
int		process_config_line(char *clean_line, int fd, char *line);
int		parse_file_content(int fd, t_game *game, char *map_lines[1000]);
int		build_game_map(t_game *game, char **map_lines, int map_count);
int		validate_game_map(t_game *game);
int		is_valid_map_line(char *line);
t_game	*read_file(char *filepath);

// UTILS
void	free_arr(char **arr);
char	*skip_white_spaces(char *line);
char	*clean_line_str(char *line);

// SAVE PARAMS
int		save_floor(t_game *game, char *line);
int		save_ceiling(t_game *game, char *line);
int		save_rgb(t_game *game, char **lines);
int		save_textures(t_game *game, char **lines);
int		save_params(t_game *game, char **lines);

// PLAYER POS
void	player_facing_north(t_game *game);
void	player_facing_south(t_game *game);
void	player_facing_east(t_game *game);
void	player_facing_west(t_game *game);
int		save_player_direction(t_game *game);

// EXEC
// MLX INIT
int		render_frame(void	*param);
void	ft_destroy(t_mlx_game *game);
int		ft_init(t_mlx_game *game);

// KEYBINDS
int		handle_exit(t_mlx_game *game);
int		ft_look(int keycode, t_game *game);
int		ft_movement(int keycode, t_game *game);
int		key_handle(int keycode, void *param);

// PLAYER MOVEMENT
int		is_wall(t_map *map, double x, double y);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// TEXTURES
void	load_xpm(t_mlx_game *game, t_texture *tex, char *path);
void	init_textures(t_mlx_game *game);

// RAYCASTING
void	my_mlx_pixel_put(t_texture *texture, int x, int y, int color);
void	calculate_ray_position_and_direction(t_mlx_game *game, int x);
void	calculate_step_and_side_dist(t_mlx_game *game);
void	perform_dda(t_mlx_game *game);
void	calculate_wall_distance_and_height(t_mlx_game *game);
void	draw_vertical_line(t_mlx_game *game, int x);
void	raycasting(t_mlx_game *game);

// BONUS
// MOUSE
int		init_mouse(t_mlx_game *mlx_game);
int		toggle_mouse_visibility(t_mlx_game *mlx_game, int show);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
int		handle_mouse(int x, int y, t_mlx_game *mlx_game);

// DOORS
void	load_door(t_mlx_game *game);
int		is_near_door(t_game *game, int map_x, int map_y);
void	check_door_interaction(t_mlx_game *game);
int		handle_doors(t_mlx_game *game);

#endif
