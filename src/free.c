/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:57:50 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 15:11:24 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_mlx(t_window *window)
{
	mlx_destroy_display(window->mlx);
	free(window->mlx);
}

void	free_textures(t_window *window)
{
	if (window->textures->no)
		mlx_destroy_image(window->mlx, window->textures->no->img);
	if (window->textures->so)
		mlx_destroy_image(window->mlx, window->textures->so->img);
	if (window->textures->we)
		mlx_destroy_image(window->mlx, window->textures->we->img);
	if (window->textures->ea)
		mlx_destroy_image(window->mlx, window->textures->ea->img);
	free(window->textures->we);
	free(window->textures->so);
	free(window->textures->no);
	free(window->textures->ea);
	free(window->textures->floor);
	free(window->textures->ceilling);
	free(window->textures);
	free_mlx(window);
}

int	free_map(t_window *window, char **arguments, char *line, int fd)
{
	int	i;

	i = 0;
	free(line);
	while (get_next_line(fd, &line))
	{
		free(line);
	}
	free(line);
	if (arguments)
		clear_array(arguments);
	free_textures(window);
	error_message_handler(2);
	exit(1);
	return (0);
}

int	free_all(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->map.y)
	{
		free(window->map.map[i]);
		i++;
	}
	free(window->map.map);
	mlx_destroy_image(window->mlx, window->image.img);
	mlx_destroy_window(window->mlx, window->win);
	free_textures(window);
	return (0);
}
