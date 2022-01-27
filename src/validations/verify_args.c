/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:53 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:58:55 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	initialize_structs(t_window *window)
{
	window->textures->no = NULL;
	window->textures->so = NULL;
	window->textures->we = NULL;
	window->textures->ea = NULL;
	window->textures->floor = NULL;
	window->textures->ceilling = NULL;
	window->map.initial_line = 0;
	window->map.n_breaks = 0;
	window->map.is_after = 0;
	window->map.y = 0;
	window->player.x = 0.0;
	window->player.y = 0.0;
	window->key.back = 0;
	window->key.up = 0;
	window->key.left = 0;
	window->key.right = 0;
	window->key.turn_left = 0;
	window->key.turn_right = 0;
}

int	verify_args(t_window *window, int argc, char **argv)
{
	int	folder;

	if (argc > 2 || !argv[1])
	{
		free_mlx(window);
		error_message_handler(1);
		return (1);
	}
	window->textures = malloc(sizeof(t_textures));
	initialize_structs(window);
	return (0);
}
