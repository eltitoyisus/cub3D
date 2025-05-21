/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:45:35 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/21 09:45:35 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init_draw_data(t_draw_data *draw_data)
{
	draw_data->start = 0;
	draw_data->end = 0;
	draw_data->color = 0;
}

void	init_config_data(t_config_data *config_data)
{
	config_data->clean_line = NULL;
	config_data->line = NULL;
	config_data->fd = -1;
	config_data->cfg = NULL;
	config_data->count = NULL;
}

void	init_flood_context(t_flood_context *flood_context)
{
	flood_context->grid = NULL;
	flood_context->width = 0;
	flood_context->height = 0;
	flood_context->breached = NULL;
}
