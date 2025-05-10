/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:55:06 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/09 08:55:06 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		return (printf("Error: No map file provided\n"), 1);
	}
	if (valid_arg(argv[1]))
		printf("Valid extension\n");
}
