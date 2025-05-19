/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:55:09 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 08:55:09 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# define WIDTH 2000
# define HEIGHT 1300

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define LOOK_RIGHT 65363
# define LOOK_LEFT 65361

#define MOVE_SPEED 0.2
#define MOUSE_SPEED 0.02

#define DOOR_DISTANCE 2

#include "main.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "../minilibx/mlx_int.h"

//other libraries
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#endif