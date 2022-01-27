/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:59:43 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:59:45 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	verify_texture_arguments(t_window *window, char **arguments)
{
	if (arguments[1] && arguments[2])
		return (0);
	if (arguments[1])
		return (1);
	return (0);
}

static t_image	*set_texture(t_window *window, char **arguments)
{
	t_image	*t;

	t = malloc(sizeof(t_image));
	t->img = mlx_xpm_file_to_image(window->mlx, arguments[1], &t->width,
			&t->height);
	if (!t->img)
		return (0);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel, &t->line_length,
			&t->endian);
	return (t);
}

int	verify_texture(t_window *window, char **arguments)
{
	if (!verify_texture_arguments(window, arguments))
		return (0);
	if (ft_str_is_equal(arguments[0], "NO"))
		window->textures->no = set_texture(window, arguments);
	else if (ft_str_is_equal(arguments[0], "SO"))
		window->textures->so = set_texture(window, arguments);
	else if (ft_str_is_equal(arguments[0], "WE"))
		window->textures->we = set_texture(window, arguments);
	else if (ft_str_is_equal(arguments[0], "EA"))
		window->textures->ea = set_texture(window, arguments);
	return (1);
}
